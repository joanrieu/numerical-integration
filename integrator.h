#pragma once
#include <array>
#include <functional>
#include <iostream>

template<class T, size_t N>
struct Integration {

  typedef T Value;
  typedef std::array<Value, N> State;
  typedef std::function<void(const State&, State&)> Derivator;
  typedef std::function<void(State&, Derivator, Value)> Integrator;

  static void apply(State& state, const State& derivative, Value step) {
    for (size_t i = 0; i < N; ++i)
      state[i] += derivative[i] * step;
  }

  static void Euler(State& state, Derivator derivator, Value step) {
    State derivative;
    derivator(state, derivative);
    apply(state, derivative, step);
  }

  static void RK4(State& state, Derivator derivator, Value step) {

    std::array<T, N> s, d1, d2, d3, d4;

    derivator(state, d1);

    s = state;
    apply(s, d1, step / 2);
    derivator(s, d2);

    s = state;
    apply(s, d2, step / 2);
    derivator(s, d3);

    s = state;
    apply(s, d3, step);
    derivator(s, d4);

    for (size_t i = 0; i < N; ++i)
      state[i] += (d1[i] / 6 + d2[i] / 3 + d3[i] / 3 + d4[i] / 6) * step;

  }

  static void output(
    const std::array<std::string, N+1>& names,
    State& state,
    Derivator derivator,
    Integrator integrator,
    T step,
    T end
  ) {

    std::cout << names[0];
    for (size_t i = 0; i < N; ++i)
      std::cout << '\t' << names[i+1];
    std::cout << std::endl;

    for (T time = 0; time < end; time += step) {
      integrator(state, derivator, step);
      std::cout << time;
      for (size_t i = 0; i < N; ++i)
        std::cout << '\t' << state[i];
      std::cout << std::endl;
    }

  }

};
