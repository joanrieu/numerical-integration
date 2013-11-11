#include <sstream>
#include "integrator.h"

int main(int argc, char** argv) {

  const double sigma = 10.;
  const double beta = 8. / 3.;
  double rho = 28.;
  if (argc == 2) {
    std::istringstream ss(argv[1]);
    ss >> rho;
  }

  typedef Integration<double, 3> Lorenz;
  Lorenz::Derivator derivator = [&](const Lorenz::State& k, Lorenz::State& d) {
    d[0] = sigma * (k[1] - k[0]);
    d[1] = k[0] * (rho - k[2]) - k[1];
    d[2] = k[0] * k[1] - beta * k[2];
  };

  Lorenz::State state = { 5, -5, 20 };
  Lorenz::output({ "t", "x", "y", "z" }, state, derivator, Lorenz::RK4, .001, 20.);

}
