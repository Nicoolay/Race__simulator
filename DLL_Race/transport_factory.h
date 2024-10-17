#pragma once
#include "API.h"
#include "Transport.h"
#include "Ground.h"
#include "4wd_boots.h"
#include "Broom.h"
#include "Camel.h"
#include "Eagle.h"
#include "Fast_camel.h"
#include "Kentavr.h"
#include "Magic_carpet.h"


#ifdef API_EXPORTS
#define TRANSPORT_FACTORY_API __declspec(dllexport)
#else
#define TRANSPORT_FACTORY_API __declspec(dllimport)
#endif

TRANSPORT_FACTORY_API Transport** makeTransports(size_t& total_transports);