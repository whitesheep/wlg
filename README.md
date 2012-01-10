Word List Generator
===================

  wlg: Word List Generator 
  version: 0.5
  coded by white_sheep
  
  site: http://www.marcorondini.eu - http://www.ihteam.net
  twitter: http://www.twitter.com/white__sheep


___________
Dipendence:


	• gmp
	• boost


__________
Build:


	• Linux:
		`make`
	• Mac Osx
		`make -f Makefile_osx`

________________
Allowed options:

	 -h [ --help ]                         produce help message
	 -v [ --version ]                      show version
	 -r [ --credits ]                      show credits

	 -e [ --extract ] arg                   set string to extract
	 -c [ --compat ] arg                    set counter to compat

	 -g [ --gen ]                           start wordlist generator

	 -f [ --filename ] arg                  set filename 

	 -C [ --charset ] arg (=ABCDEFGHIJKLMNOPQRSTUVXYZabcdefghijklmnopqrstuvwxyz0123456789"_-.,:;!%&/()=?'^*+][@)
	                                        set charset

	 -o [ --using_word ]                    using word
	 -w [ --start_word ] arg                set start word
	 -W [ --end_word ] arg                  set end word

	 -n [ --using_index ]                   using index
	 -i [ --start_int ] arg (=0)            set start counter
	 -I [ --end_int ] arg (=0)              set end counter

	 -l [ --using_length ]                  using length
	 -m [ --min_length ] arg (=0)           set min word length
	 -M [ --max_length ] arg (=0)           set max word length


_________
Examples:


	extract function: return iteration number 
  
  	`wlg -e ciao
  	15669092`
  
  	compat function: return string about iteration number
  
  	`wlg -c 15669092
  	ciao`
  
  	gen function: generate wordlist
  		• using word index
  			`wlg -g -o -w ciao` ( infinite wordlist creation )
  			`wlg -g -o -w ciao -W ciaoc` ( wordlist between ciao and ciaoc )
  		• using iteration index
  			`wlg -g -n -i 10000000000000000000` ( infinite wordlist creation )
  			`wlg -g -n -i 100 -I 123123123123`( wordlist between 100 and 123123123123 iteration number )
  		• using word length
  			`wlg -g -l -m 1` ( infinite wordlist creation )
  			`wlg -g -l -m 3 -M 8` ( wordlist with min length 1 and max length 8 )


_________
Features:


  	Using file for output 
  		`wlg -g -l -m 1 -f wl.txt`
  	
	Set charset
  		`wlg -g -l -m 1 -C 0123456789 -f wl.txt`