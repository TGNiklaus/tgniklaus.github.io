#include "DTL.h"
#include <iostream>
using namespace dtl;
using namespace std;

int main()
{
	try
	{
		// Connect to the Database
		DBConnection::GetDefaultConnection().Connect("UID=johndoe;PWD=secret:DSN=sales2005;");
		
		DynamicDBView<> view("sales_Q3", "*");
		
		copy(view.begin(), view.end(), ostream_iterator<variant_row>(cout, "\n"));
	}
	
	catch (std::exception &ex)
	{
		cerr << ex.what() << endl;
	}
	
	return 0;
}