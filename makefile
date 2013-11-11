CXXFLAGS+=-std=c++11

plot.svg: plot.gp lorenz brusselator makefile
	gnuplot -e "set terminal svg size 2400,1600 ; set output '$@'" $<

lorenz: lorenz.cpp integrator.h
	$(CXX) $(CXXFLAGS) -o $@ $<

brusselator: brusselator.cpp integrator.h
	$(CXX) $(CXXFLAGS) -o $@ $<

.PHONY: distclean clean

distclean: clean
	rm -f plot.svg

clean:
	rm -f lorenz brusselator
