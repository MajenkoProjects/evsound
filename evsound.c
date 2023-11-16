#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <samplerate.h>
#include <sndfile.h>

#define EV_PRESS 1
#define EV_RELEASE 2
#define EV_TYPE 3


#define EV_MOUSE_LEFT 	0x10001
#define EV_MOUSE_RIGHT 	0x10002
#define EV_MOUSE_MIDDLE 0x10003

#define EV_ESC			0x01001
#define EV_DEL			0x01002
#define EV_LSHIFT		0x01003
#define EV_LALT			0x01004
#define EV_LCTRL		0x01005
#define EV_RSHIFT		0x01006
#define EV_RALT			0x01007
#define EV_RCTRL		0x01008
#define EV_ENTER		0x01009
#define EV_BACKSPACE	0x0100a
#define EV_TAB			0x0100b
#define EV_PAUSE		0x0100c
#define EV_SCROLL		0x0100d
#define EV_PRINT		0x0100e
#define EV_HOME			0x0100f
#define EV_END			0x01010
#define EV_PGUP			0x01011
#define EV_PGDN			0x01012
#define EV_LEFT			0x01013
#define EV_RIGHT		0x01014
#define EV_UP			0x01015
#define EV_DOWN			0x01016
#define EV_SPACE		0x01017

#define EV_KPENTER		0x03001
#define EV_KP1			0x03002
#define EV_KP2			0x03003
#define EV_KP3			0x03004
#define EV_KP4			0x03005
#define EV_KP5			0x03006
#define EV_KP6			0x03007
#define EV_KP7			0x03008
#define EV_KP8			0x03009
#define EV_KP9			0x0300a
#define EV_KP0			0x0300b
#define EV_KPPERIOD		0x0300c
#define EV_KPASTERISK	0x0300d
#define EV_KPPLUS		0x0300e
#define EV_KPMINUS		0x0300f
#define EV_KPSLASH		0x03010


#define EV_F1			0x02001
#define EV_F2			0x02002
#define EV_F3			0x02003
#define EV_F4			0x02004
#define EV_F5			0x02005
#define EV_F6			0x02006
#define EV_F7			0x02007
#define EV_F8			0x02008
#define EV_F9			0x02009
#define EV_F10			0x02010
#define EV_F11			0x02011
#define EV_F12			0x02012

struct sample_map {
	int event;	
	const char *prefix;
};

struct sample_map sampleMap[] = {
	{EV_MOUSE_LEFT, 	"MOUSE_LEFT"},
	{EV_MOUSE_RIGHT, 	"MOUSE_RIGHT"},
	{EV_MOUSE_MIDDLE, 	"MOUSE_MIDDLE"},
	{EV_ESC,			"ESC"},
	{EV_DEL,			"DEL"},
	{EV_LSHIFT,			"LSHIFT"},
	{EV_LALT,			"LALT"},
	{EV_LCTRL,			"LCTRL"},
	{EV_RSHIFT,			"RSHIFT"},
	{EV_RALT,			"RALT"},
	{EV_RCTRL,			"RCTRL"},
	{EV_ENTER,			"ENTER"},
	{EV_BACKSPACE,		"BACKSPACE"},
	{EV_SPACE,			"SPACE"},
	{EV_TAB,			"TAB"},
	{EV_PAUSE,			"PAUSE"},
	{EV_SCROLL,			"SCROLL"},
	{EV_PRINT,			"PRINT"},
	{EV_HOME,			"HOME"},
	{EV_END,			"END"},
	{EV_PGUP,			"PGUP"},
	{EV_PGDN,			"PGDN"},
	{EV_LEFT,			"LEFT"},
	{EV_RIGHT,			"RIGHT"},
	{EV_UP,				"UP"},
	{EV_DOWN,			"DOWN"},
	{EV_KPENTER,		"KP_ENTER"},
	{EV_KP1,			"KP_1"},
	{EV_KP2,			"KP_2"},
	{EV_KP3,			"KP_3"},
	{EV_KP4,			"KP_4"},
	{EV_KP5,			"KP_5"},
	{EV_KP6,			"KP_6"},
	{EV_KP7,			"KP_7"},
	{EV_KP8,			"KP_8"},
	{EV_KP9,			"KP_9"},
	{EV_KP0,			"KP_0"},
	{EV_KPPERIOD,		"KP_PERIOD"},
	{EV_KPASTERISK,		"KP_ASTERISK"},
	{EV_KPPLUS,			"KP_PLUS"},
	{EV_KPMINUS,		"KP_MINUS"},
	{EV_KPSLASH,		"KP_EQUALS"},
	{EV_F1,				"F1"},
	{EV_F2,				"F2"},
	{EV_F3,				"F3"},
	{EV_F4,				"F4"},
	{EV_F5,				"F5"},
	{EV_F6,				"F6"},
	{EV_F7,				"F7"},
	{EV_F8,				"F8"},
	{EV_F9,				"F9"},
	{EV_F10,			"F10"},
	{EV_F11,			"F11"},
	{EV_F12,			"F12"},
	{'`',				"BACKTICK"},
	{'1',				"1"},
	{'2',				"2"},
	{'3',				"3"},
	{'4',				"4"},
	{'5',				"5"},
	{'6',				"6"},
	{'7',				"7"},
	{'8',				"8"},
	{'9',				"9"},
	{'0',				"0"},
	{'-',				"MINUS"},
	{'=',				"EQUALS"},
	{'Q',				"Q"},
	{'W',				"W"},
	{'E',				"E"},
	{'R',				"R"},
	{'T',				"T"},
	{'Y',				"Y"},
	{'U',				"U"},
	{'I',				"I"},
	{'O',				"O"},
	{'P',				"P"},
	{'[',				"BRACKET_OPEN"},
	{']',				"BRACKET_CLOSE"},
	{'A',				"A"},
	{'S',				"S"},
	{'D',				"D"},
	{'F',				"F"},
	{'G',				"G"},
	{'H',				"H"},
	{'J',				"J"},
	{'K',				"K"},
	{'L',				"L"},
	{';',				"SEMICOLON"},
	{'\'',				"APOSTROPHE"},
	{'#',				"HASH"},
	{'\\',				"BACKSLASH"},
	{'Z',				"Z"},
	{'X',				"X"},
	{'C',				"C"},
	{'V',				"V"},
	{'B',				"B"},
	{'N',				"N"},
	{'M',				"M"},
	{',',				"COMMA"},
	{'.',				"PERIOD"},
	{'/',				"SLASH"},
	{0, 0}
};



struct event {
	float ts;
	int type;
	int data;
	int x;
	int y;
	struct event *next;
};

struct sample_info {
	float *data;
	int frames;
	int channels;
};

struct sample {
	int event;
	struct sample_info press;
	struct sample_info release;
	struct sample_info type;
	struct sample *next;
};

struct event *events = NULL;
struct sample *samples = NULL;



void PANIC(const char *msg) {
	fprintf(stderr, "PANIC: %s\n", msg);
	exit(10);
}



int loadSample(const char *filename, struct sample_info *info) {
	SF_INFO sfi;
	printf("Loading sample %s\n", filename);
	SNDFILE *f = sf_open(filename, SFM_READ, &sfi);
	if (!f) {
		printf("Warning: sample %s not found.\n", filename);
		return 0;
	}

	float *data = malloc(sizeof(float) * sfi.frames * sfi.channels);
	if (data == NULL) PANIC("Unable to allocate sample data");
	sf_readf_float(f, data, sfi.frames);
	sf_close(f);

	float ratio = 48000.0 / (float)sfi.samplerate;

	printf("Ratio: %f\n", ratio);

	float *resampled = malloc(sizeof(float) * sfi.frames * sfi.channels * ratio);
	if (resampled == NULL) PANIC("Unable to allocate resampled data");

	int err = 0;


	SRC_STATE *sri = src_new(SRC_SINC_BEST_QUALITY, sfi.channels, &err);
	SRC_DATA sdat = {
		.data_in = data,
		.data_out = resampled,
		.input_frames = sfi.frames,
		.output_frames = (sfi.frames * ratio),
		.src_ratio = ratio
	};

	src_process(sri, &sdat);
	src_delete(sri);
	free(data);

	info->data = resampled;
	info->channels = sfi.channels;
	info->frames = sfi.frames * ratio;

	return 1;

}









void printEvent(struct event *e) {
	printf("%f %s %05x\n", e->ts, e->type == EV_PRESS ? "PRESS" : (e->type == EV_RELEASE ? "RELEASE" : "TYPE"), e->data);
}

int strtoev(const char *n, const char *loc) {
	if (n[1] == 0) {
		return n[0];
	}

	if (strcasecmp(n, "mouse_left") == 0) return EV_MOUSE_LEFT;
	if (strcasecmp(n, "mouse_right") == 0) return EV_MOUSE_RIGHT;
	if (strcasecmp(n, "mouse_middle") == 0) return EV_MOUSE_MIDDLE;

	if (strcasecmp(n, "esc") == 0) return EV_ESC;
	if (strcasecmp(n, "Del") == 0) return EV_DEL;
	if (strcasecmp(n, "Shift") == 0) {
		if (loc != NULL) {
			if (strcasecmp(loc, "L") == 0) return EV_LSHIFT;
			if (strcasecmp(loc, "R") == 0) return EV_RSHIFT;
		}
		return EV_LSHIFT;
	}
	if (strcasecmp(n, "Alt") == 0) {
		if (loc != NULL) {
			if (strcasecmp(loc, "L") == 0) return EV_LALT;
			if (strcasecmp(loc, "R") == 0) return EV_RALT;
		}
		return EV_LALT;
	}
	if (strcasecmp(n, "CTRL") == 0) {
		if (loc != NULL) {
			if (strcasecmp(loc, "L") == 0) return EV_LCTRL;
			if (strcasecmp(loc, "R") == 0) return EV_RCTRL;
		}
		return EV_LCTRL;
	}
	if (strcasecmp(n, "enter") == 0) return EV_ENTER;
	if (strcasecmp(n, "backspace") == 0) return EV_BACKSPACE;
	if (strcasecmp(n, "space") == 0) return EV_SPACE;
	if (strcasecmp(n, "tab") == 0) return EV_TAB;
	if (strcasecmp(n, "Pau_Brk") == 0) return EV_PAUSE;
	if (strcasecmp(n, "Scr_Lck") == 0) return EV_SCROLL;
	if (strcasecmp(n, "PrSc_SysRq") == 0) return EV_PRINT;
	if (strcasecmp(n, "Home") == 0) return EV_HOME;
	if (strcasecmp(n, "End") == 0) return EV_END;
	if (strcasecmp(n, "pgup") == 0) return EV_PGUP;
	if (strcasecmp(n, "pgdn") == 0) return EV_PGDN;
	if (strcasecmp(n, "left_arrow") == 0) return EV_LEFT;
	if (strcasecmp(n, "right_arrow") == 0) return EV_RIGHT;
	if (strcasecmp(n, "up_arrow") == 0) return EV_UP;
	if (strcasecmp(n, "down_arrow") == 0) return EV_DOWN;

	if (strcasecmp(n, "kpenter") == 0) return EV_KPENTER;
	if (strcasecmp(n, "kp1") == 0) return EV_KP1;
	if (strcasecmp(n, "kp2") == 0) return EV_KP2;
	if (strcasecmp(n, "kp3") == 0) return EV_KP3;
	if (strcasecmp(n, "kp4") == 0) return EV_KP4;
	if (strcasecmp(n, "kp5") == 0) return EV_KP5;
	if (strcasecmp(n, "kp6") == 0) return EV_KP6;
	if (strcasecmp(n, "kp7") == 0) return EV_KP7;
	if (strcasecmp(n, "kp8") == 0) return EV_KP8;
	if (strcasecmp(n, "kp9") == 0) return EV_KP9;
	if (strcasecmp(n, "kp0") == 0) return EV_KP0;
	if (strcasecmp(n, "kp.") == 0) return EV_KPPERIOD;
	if (strcasecmp(n, "kp*") == 0) return EV_KPASTERISK;
	if (strcasecmp(n, "kp+") == 0) return EV_KPPLUS;
	if (strcasecmp(n, "kp-") == 0) return EV_KPMINUS;
	if (strcasecmp(n, "kp/") == 0) return EV_KPSLASH;

	if (strcasecmp(n, "f1") == 0) return EV_F1;
	if (strcasecmp(n, "f2") == 0) return EV_F2;
	if (strcasecmp(n, "f3") == 0) return EV_F3;
	if (strcasecmp(n, "f4") == 0) return EV_F4;
	if (strcasecmp(n, "f5") == 0) return EV_F5;
	if (strcasecmp(n, "f6") == 0) return EV_F6;
	if (strcasecmp(n, "f7") == 0) return EV_F7;
	if (strcasecmp(n, "f8") == 0) return EV_F8;
	if (strcasecmp(n, "f9") == 0) return EV_F9;
	if (strcasecmp(n, "f10") == 0) return EV_F10;
	if (strcasecmp(n, "f11") == 0) return EV_F11;
	if (strcasecmp(n, "f12") == 0) return EV_F12;


	printf("Unknown event: %s\n", n);

	return 0xFFFFF;
}

void readEvents(FILE *f) {
	fseek(f, 0, SEEK_SET);

	char line[1024];

	struct event *tail = events;



	while (!feof(f)) {
		fgets(line, 1024, f);
		while ((strlen(line) > 0) && (line[strlen(line)-1] < ' ')) {
			line[strlen(line)-1] = 0;
		}

		char *ts = strtok(line, " ");
		char *direction = strtok(NULL, " ");
		char *object = strtok(NULL, " ");
		char *at = strtok(NULL, " ");
		char *x = strtok(NULL, " ");
		char *y = strtok(NULL, " ");

		if (object != NULL) {
			struct event *e = malloc(sizeof(struct event));
			if (e == NULL) PANIC("Unable to allocate new event");

			e->ts = strtof(line, NULL);
			if (strcmp(direction, "press") == 0) {
				e->type = EV_PRESS;
			} else {
				e->type = EV_RELEASE;
			}

			e->data = strtoev(object, at);

			e->next = NULL;

			if (tail == NULL) {
				events = e;
			} else {
				tail->next = e;
			}
			tail = e;

		}
	}
}

void dumpEvents() {
	for (struct event *e = events; e; e = e->next) {
		printEvent(e);
	}
}

void freeEvents() {
	struct event *x = events;
	while (x != NULL) {
		struct event *n = x->next;
		free(x);
		x = n;
	}
}

void freeSamples() {
	struct sample *s = samples;
	while (s != NULL) {
		struct sample *n = s->next;
		if (s->press.data != NULL) free(s->press.data);
		if (s->release.data != NULL) free(s->release.data);
		if (s->type.data != NULL) free(s->type.data);
		free(s);
		s = n;
	}
}

void compressEvents() {
	for (struct event *e = events; e; e = e->next) {
		if (e->next != NULL) {
			if ((e->type == EV_PRESS) && (e->data == e->next->data) && (e->next->type == EV_RELEASE)) {
				if (e->next->ts - e->ts < 0.05) {
					e->type = EV_TYPE;
					struct event *t = e->next;
					e->next = t->next;
					free(t);
				}
			}
		}
	}
}

const char *findPrefixForEvent(int event) {
	for (struct sample_map *sm = sampleMap; sm->event != 0; sm++) {
		if (sm->event == event) return sm->prefix;
	}
	return NULL;
}

struct sample *findSampleForEvent(int event) {
	printf("Looking for event type %05x\n", event);
	for (struct sample *s = samples; s; s = s->next) {
		printf("  %05x\n", s->event);
		if (s->event == event) return s;
	}
	return NULL;
}

void loadEventSamples() {
	for (struct event *e = events; e; e = e->next) {

		const char *prefix = findPrefixForEvent(e->data);
		printf("Prefix: %s\n", prefix);
		struct sample *sample = findSampleForEvent(e->data);
		if (sample == NULL) {
			sample = malloc(sizeof(struct sample));
			if (sample == NULL) PANIC("Unable to allocate new sample");
			bzero(sample, sizeof(struct sample));
			sample->event = e->data;
			if (samples == NULL) {
				samples = sample;
			} else {
				struct sample *s = samples;
				while (s->next != NULL) {
					s = s->next;
				}
				s->next = sample;
			}
		}

		char fn[1024];

		if (e->type == EV_PRESS) {
			if (sample->press.data == NULL) {
				sprintf(fn, "/home/matt/Sounds/Keyboards/Dell/05N292/Audio/%s_Press.wav", prefix);
				loadSample(fn, &sample->press);
			}
		} else if (e->type == EV_RELEASE) {
			if (sample->release.data == NULL) {
				sprintf(fn, "/home/matt/Sounds/Keyboards/Dell/05N292/Audio/%s_Release.wav", prefix);
				loadSample(fn, &sample->release);
			}
		} else if (e->type == EV_TYPE) {
			if (sample->type.data == NULL) {
				sprintf(fn, "/home/matt/Sounds/Keyboards/Dell/05N292/Audio/%s_Type.wav", prefix);
				loadSample(fn, &sample->type);
			}
		}
	}
}

void mixSamples(float *in1, float *in2, float *out, int num) {
	for (int i = 0; i < num; i++) {
		float in1l = in1[i * 2];
		float in1r = in1[i * 2 + 1];
		float in2l = in2[i * 2];
		float in2r = in2[i * 2 + 1];
		float outl, outr;
/*

		if (in1l < 0.0 && in2l < 0.0) {
			outl = (in1l * in2l);
		} else {
			outl = (2.0 * (in1l - in2l)) - ((in1l * in2l)) - 1.0;
		}

		if (in1r < 0.0 && in2r < 0.0) {
			outr = (in1r * in2r);
		} else {
			outr = (2.0 * (in1r - in2r)) - ((in1r * in2r)) - 1.0;
		}
*/

		outl = (in1l + in2l) / 2.0;
		outr = (in1r + in2r) / 2.0;

		out[i * 2] = outl;
		out[i * 2 + 1] = outr;
	}
}


void renderEvents(const char *filename) {
	SF_INFO sfi = {
		.samplerate = 48000,
		.channels = 2,
		.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16 | SF_ENDIAN_LITTLE,
		.seekable = 1
	};

	SNDFILE *f = sf_open(filename, SFM_RDWR, &sfi);

	for (struct event *e = events; e; e = e->next) {

		sf_count_t offset = e->ts * 48000.0;

		sf_seek(f, offset, SEEK_SET);

		struct sample *s = findSampleForEvent(e->data);
		if (s != NULL) {
			struct sample_info *si = NULL;
			switch (e->type) {
				case EV_PRESS:
					si = &s->press;
					break;
				case EV_RELEASE:
					si = &s->release;
					break;
				case EV_TYPE:
					si = &s->type;
					break;
			}

			if (si->data != NULL) {
				float *inbuf = malloc(sizeof(float) * 2 * si->frames);
				if (inbuf == NULL) PANIC("Unable to allocate input buffer");
				float *mixbuf = malloc(sizeof(float) * 2 * si->frames);
				if (mixbuf == NULL) PANIC("Unable to allocate mix buffer");

				sf_readf_float(f, inbuf, si->frames);

				mixSamples(si->data, inbuf, mixbuf, si->frames);
				sf_seek(f, offset, SEEK_SET);
				int wr = sf_writef_float(f, si->data, si->frames);
				free(inbuf);
				free(mixbuf);
			} else {
				printf("Missing sample data for %05x %d\n", e->data, e->type);
			}
		}
	}

	sf_close(f);
	
	
}

int main(int argc, char **argv) {
	FILE *evfile = fopen(argv[1], "r");
	readEvents(evfile);
	fclose(evfile);
	compressEvents();
	loadEventSamples();

	for (struct sample *s = samples; s; s = s->next) {
		printf("Type %05x Press: %p %d %d Release: %p %d %d Type: %p %d %d\n", 
			s->event, s->press.data, s->press.frames, s->press.channels,
			s->release.data, s->release.frames, s->release.channels,
			s->type.data, s->type.frames, s->type.channels
		);
	}

	renderEvents("events.wav");

	freeEvents();
	freeSamples();

	return 0;
}
