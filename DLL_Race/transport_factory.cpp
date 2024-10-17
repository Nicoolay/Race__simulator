#include <iostream>
#include "transport_factory.h"

Transport** makeTransports(size_t& total_transports)
{
	total_transports = 7; //у вас будет максимальное число транспортов
	Transport** trans_arr = new Transport * [total_transports];
	trans_arr[0] = new WD_boots();
	trans_arr[1] = new Broom();
	trans_arr[2] = new Camel();
	trans_arr[3] = new Kentavr();
	trans_arr[4] = new Eagle();
	trans_arr[5] = new Fast_Camel();
	trans_arr[6] = new Magic_carpet();
	return trans_arr;
}
