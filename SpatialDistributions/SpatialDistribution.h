#ifndef _SpatialDistribution_
#define _SpatialDistribution_

/*
* An object of this class represents a probability
* distribution over the space of possible positions
* in N dimensions.
* They have parameters, and two kinds of proposal
* distributions are available:
* 1) Move the parameters, positions fixed
* 2) Move the parameters, move the positions as well
* or you can just keep it fixed.
*/

#include <vector>
#include <ostream>

class SpatialDistribution
{
	private:


		// How to move the parameters (gets called by other proposals)
		virtual double perturb_parameters() = 0;

	public:
		SpatialDistribution();

		// Generate parameters from the prior
		virtual void fromPrior() = 0;

		// These must be implemented
		virtual double position_log_pdf(const std::vector<double>& position) const = 0;

		// Method to transform uniform(0, 1)s to and from
		// the distribution
		// (analogous to cdf and inverse cdf)
		virtual void position_from_uniform(std::vector<double>& vec) const = 0;
		virtual void position_to_uniform(std::vector<double>& vec) const = 0;

		// Type 1 proposal as defined above
		double perturb1(const std::vector< std::vector<double> >& positions);

		// Type 2 proposal as defined above
		double perturb2(std::vector< std::vector<double> >& positions);

		// Print parameters to stream
		virtual void print(std::ostream& out) const = 0;
};

#endif

