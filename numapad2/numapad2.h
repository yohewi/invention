#pragma once

#ifndef NUMAPAD2_H
#define NUMAPAD2_H

#include "quantum.h"
#include "matrix.h"

#define LAYOUT( \
	K00, K01, K02, K03, \
	K10, K11, K12, K13, \
	K20, K21, K22, K23, \
	K30, K31, K32, K33  \
) \
{ \
	{ K00,   K01,   K02,   K03 }, \
	{ K10,   K11,   K12,   K13 }, \
	{ K20,   K21,   K22,   K23 }, \
	{ K30,   K31,   K32,   K33 }  \
}
#endif