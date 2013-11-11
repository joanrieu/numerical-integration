#include "integrator.h"

int main() {

  typedef Integration<double, 2> Brusselator;
  Brusselator::Derivator derivator = [](const Brusselator::State& k, Brusselator::State& d) {
    d[0] = 1. + k[0] * k[0] * k[1] - 4 * k[0];
    d[1] = 3. * k[0] - k[0] * k[0] * k[1];
  };

  Brusselator::State state = { 1.5, 3. };
  Brusselator::output({ "t", "x", "y" }, state, derivator, Brusselator::RK4, .001, 20.);

}
