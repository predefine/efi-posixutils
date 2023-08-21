#pragma once

#define APPLET_ERROR(error) {printf("%s: %s\n", argv[0], error); return 1;}
#define APPLET_ERROR_NUMBER(error) {printf("%s: %d\n", argv[0], error); return 1;}