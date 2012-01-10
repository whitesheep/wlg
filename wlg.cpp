/*
 *  wlg.cpp
 *  
 *
 *  Created by Marco Rondini on 08/01/12.
 *  g++ -o wlg wlg.cpp -lgmp -lboost_program_options -I/opt/local/include/ -L/opt/local/lib/
 *
 */

#include <iostream>
#include <string>

#include <gmp.h>
#include <gmpxx.h>

#include <boost/program_options.hpp>

#include "wlg.h"

using namespace std;
using namespace boost;

namespace po = boost::program_options;

po::options_description desc("Allowed options");

string version("0.5");

void credits(){
	cout << "wlg: Word List Generator " << endl;
	cout << "version: " << version << endl;
	cout << "coded by white_sheep" << endl;
	cout << endl;
	cout << "site: http://www.marcorondini.eu - http://www.ihteam.net" << endl;
	cout << "twitter: http://www.twitter.com/white__sheep" << endl;
	return;
}

string WLG::compat(mpz_class decimal){
	
	mpz_class tmp;
	
	mpz_class base(charset.length() - 1);
	std::string result("");
	const char *charset__(charset.c_str());
	
	do {
		--decimal;  // fix to add 0 position
		tmp = decimal % base;
		result.push_back(charset__[tmp.get_ui()]);
		decimal = decimal / base; 
	} while(decimal != 0);
	
	return std::string(result.rbegin(), result.rend());
	
}

string WLG::extract(std::string toextr){
	
	const char *charset__(charset.c_str());
	const char *toextr__(toextr.c_str());
	mpz_class base(charset.length() - 1);
	
	int i, j;
	
	mpz_class base__(1);
	mpz_class int_ret(0);
	
	for ( i = toextr.length() - 1; i >= 0 ; i-- ){
		for ( j = 0; j < charset.length(); j++ ){
			if ( charset__[j] == toextr__[i] )
				int_ret += (j + 1) * base__;
		}
		base__ *= base;
	}
	
	return std::string(int_ret.get_str());
}

string WLG::indexFromLength(int length){
	
	const char *charset__(charset.c_str());
	std::string result("");
	
	for ( int i = 0; i < length; i++ ){
		result.push_back(charset__[0]);
	}
	
	return extract(result);
}

void WLG::OpenFile(){
	if ( filename != "" ){
		fn_res.open(filename.c_str());
	}
}

void WLG::CloseFile(){
	if ( filename != "" ){
		fn_res.close();
	}
}

void WLG::log(string txt){
	if ( filename == "" )
		cout << txt << endl;
	else 
		fn_res << txt << endl;

}

int main(int argc, char *argv[]){
	
	WLG *wlg = new WLG();
	
	string w_start(""), w_end(""), i_start(""), i_end("");
	string word(""), counter("");
	
	int min_length, max_length;
	
	mpz_class start, end;
	
	desc.add_options()
		("help,h", "produce help message")
		("version,v", "show version")
		("credits,r", "show credits")	
	
		("extract,e", po::value<string>(&word), " set string to extract")
		("compat,c",  po::value<string>(&counter), " set counter to compat")
		("gen,g", " start wordlist generator")
		
		("filename,f", po::value<string>(&wlg->filename)->default_value(""), " set filename ")
		("charset,C", po::value<string>(&wlg->charset)->default_value("ABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvwxyz0123456789\"_-.,:;!%&/()=?'^*+][@"), " set charset")
		
		("using_word,o", " using word")
		("start_word,w", po::value<string>(&w_start), " set start word")
		("end_word,W", po::value<string>(&w_end), " set end word")
		
		("using_index,n", " using index")
		("start_int,i", po::value<string>(&i_start)->default_value("0"), " set start counter")
		("end_int,I", po::value<string>(&i_end)->default_value("0"), " set end counter")
		
		("using_length,l", " using length")
		("min_length,m", po::value<int>(&min_length)->default_value(0), " set min word length")
		("max_length,M", po::value<int>(&max_length)->default_value(0), " set max word length")
	;
	
	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);
	
	if (vm.count("help")) {
		cout << desc << endl;
		return 1;
	}
	
	if (vm.count("version")) {
		cout << version << endl;
		return 1;
	}
	
	if (vm.count("credits")) {
		credits();
		return 1;
	}
	
	if (vm.count("extract")){
		
		cout << wlg->extract(word) << endl;	
	
	} else if (vm.count("compat")) {
	
		try {
			mpz_class tmp(counter);
			cout << wlg->compat(tmp) << endl;	
		} catch (string e) {
			cout << e << endl;
		}
	
	} else if (vm.count("gen")){
		
		wlg->OpenFile();
		
		if ( vm.count("using_word") ){
			
			start = wlg->extract(w_start);
			end = wlg->extract(w_end);
			
		} else if ( vm.count("using_index") ) {
			
			start = i_start;
			end = i_end;
			
		} else if ( vm.count("using_length") ) {
			
			start = wlg->indexFromLength(min_length);
			end = wlg->indexFromLength(max_length);
		
		}
		
		do {
			//cout << wlg->compat(start) << endl;
			wlg->log(wlg->compat(start));
		} while ( start++ != end );
		
		wlg->CloseFile();
		return 0;
	}
}