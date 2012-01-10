/*
 *  wlg.h
 *  
 *
 *   Created by Marco Rondini on 08/01/12.
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published
 *   by the Free Software Foundation; version 2 of the License.
 *   
 *   This program is distributed in the hope that it will be useful, but
 *   WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 *   or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 *   for more details.
 *   
 *   You should have received a copy of the GNU General Public License along
 *   with this program; if not, write to the Free Software Foundation, Inc.,
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA
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