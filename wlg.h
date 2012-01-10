/*
 *  wlg.h
 *  
 *
 *  Created by Marco Rondini on 08/01/12.
 *  
 *
 */

#include <string>
#include <fstream>

using namespace std;

class WLG {

private:
public:
	
	WLG(){};
	~WLG(){};
	
	string charset;
	string filename;
	ofstream fn_res;
	
	string compat(mpz_class decimal);
	string extract(string toextr);
	string indexFromLength(int length);
	void OpenFile();
	void CloseFile();
	void log(string filename);
};