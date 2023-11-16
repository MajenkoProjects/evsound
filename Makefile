evsound: evsound.o
	cc -o $@ $< -lsndfile -lsamplerate -ggdb3

clean:
	rm -f evsound evsound.o
