#ifndef _MyDistribution_
#define _MyDistribution_

#include <Distributions/Distribution.h>

// Based on ClassicMassInf1D from RJObject
// Think of "position x" as log-period
// and mass as amplitude
class MyDistribution:public Distribution
{
	private:
		// Limits
		double x_min, x_max, x_range;

		double center_locations;
		double diversity_locations;

		double center_logwidths;
		double diversity_logwidths;

		double diversity_logweights;

		double perturb_parameters();

	public:
		MyDistribution(double x_min, double x_max);

		void fromPrior();

		double log_pdf(const std::vector<double>& vec) const;
		void from_uniform(std::vector<double>& vec) const;
		void to_uniform(std::vector<double>& vec) const;

		void print(std::ostream& out) const;
		static const int weight_parameter = 1;

};

#endif

