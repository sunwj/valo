// Copyright © 2015 Mikko Ronkainen <firstname@mikkoronkainen.com>
// License: MIT, see the LICENSE file.

#include "Math/MathUtils.h"

namespace Raycer
{
	template <int N>
	Polynomial<N>::Polynomial()
	{
	}

	template <int N>
	Polynomial<N>::Polynomial(const double* coefficients_)
	{
		setCoefficients(coefficients_);
	}

	template <int N>
	void Polynomial<N>::setCoefficients(const double* coefficients_)
	{
		for (int i = 0; i < size; ++i)
			coefficients[i] = coefficients_[i];
	}

	template <int N>
	std::complex<double> Polynomial<N>::evaluate(const std::complex<double>& x) const
	{
		std::complex<double> y(0.0, 0.0);

		for (int i = 0; i < size; ++i)
			y += coefficients[i] * pow(x, degree - i);

		return y;
	}

	// Durand-Kerner algorithm
	// https://en.wikipedia.org/wiki/Durand%E2%80%93Kerner_method
	template <int N>
	const std::complex<double>* Polynomial<N>::findAllRoots(int maxIterations, double changeThreshold)
	{
		// normalize (so that highest degree coeff is one)
		double denominator = coefficients[0];

		for (int i = 0; i < size; ++i)
			coefficients[i] /= denominator;

		// seed roots with distributed complex values
		std::complex<double> seed(0.4, 0.9);

		for (int i = 0; i < degree; ++i)
			roots[i] = previousRoots[i] = pow(seed, i);

		for (int i = 0; i < maxIterations; ++i)
		{
			for (int j = 0; j < degree; ++j)
			{
				// numerator
				std::complex<double> temp = evaluate(roots[j]);

				// denominators
				for (int k = 0; k < degree; ++k)
				{
					if (k == j)
						continue;

					temp /= (roots[j] - roots[k]);
				}

				// rest of the equation
				roots[j] = roots[j] - temp;
			}

			// break iteration if roots are not changing much
			if (i >= 4)
			{
				bool notChanged = true;

				for (int j = 0; j < degree; ++j)
				{
					if (!MathUtils::almostSame(roots[j], previousRoots[j], changeThreshold))
					{
						notChanged = false;
						break;
					}
				}

				if (notChanged)
					break;
			}

			for (int j = 0; j < degree; ++j)
				previousRoots[j] = roots[j];
		}

		return roots;
	}

	template <int N>
	const double* Polynomial<N>::findAllPositiveRealRoots(int& count, int maxIterations, double changeThreshold, double imagZeroThreshold)
	{
		findAllRoots(maxIterations, changeThreshold);
		count = 0;

		for (int i = 0; i < degree; ++i)
		{
			if (MathUtils::almostZero(roots[i].imag(), imagZeroThreshold) && roots[i].real() > 0.0)
			{
				positiveRealRoots[count] = roots[i].real();
				count++;
			}
		}

		return positiveRealRoots;
	}

	template <int N>
	bool Polynomial<N>::findSmallestPositiveRealRoot(double& result, int maxIterations, double changeThreshold, double imagZeroThreshold)
	{
		int count;
		findAllPositiveRealRoots(count, maxIterations, changeThreshold, imagZeroThreshold);

		if (count == 0)
			return false;

		std::sort(std::begin(positiveRealRoots), std::begin(positiveRealRoots) + count);
		result = positiveRealRoots[0];

		return true;
	}
}