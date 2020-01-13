#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <X11/Xresource.h>

int
print_resource(char *resource)
{
	XrmInitialize();

	Display *display = XOpenDisplay(NULL);
	if (!display) {
		fprintf(stderr, "Failed to open display\n");
		XCloseDisplay(display);
		return EXIT_FAILURE;
	}

	char *xrmString = XResourceManagerString(display);
	if (!xrmString) {
		fprintf(stderr, "Failed to get xresource manager\n");
		XCloseDisplay(display);
		return EXIT_FAILURE;
	}

	XrmDatabase xrdb = XrmGetStringDatabase(xrmString);
	if (!xrdb) {
		fprintf(stderr, "Failed to open xrdb\n");
		XCloseDisplay(display);
		return EXIT_FAILURE;
	}

	char *type;
	XrmValue value;
	if (XrmGetResource(xrdb, resource, resource, &type, &value)) {
		XCloseDisplay(display);
		fprintf(stdout, "%s\n", value.addr);
		return 0;
	} else {
		XCloseDisplay(display);
		return EXIT_FAILURE;
	}
}

int
main(int argc, char **argv)
{
	static struct option long_options[] = {
		{ "version", no_argument, NULL, 'v' },
		{ "help", no_argument, NULL, 'h' },
	};

	switch (getopt_long(argc, argv, "hv", long_options, NULL)) {
		case 'h':
			printf("Usage: %s [OPTION]... resource\n"
				"\n"
				"Options:\n"
				" -h, --help\tDisplay this help\n"
				" -v, --version\tDislay the program version\n",
				argv[0]);
			return 0;
		case 'v':
			printf("xrdb-get v1.0\n");
			return 0;
		case -1:
			return print_resource(argv[1]);
		default:
			fprintf(stderr,
					"Try '%s --help' for more information\n",
					argv[0]);
			return EXIT_FAILURE;
	}
}

