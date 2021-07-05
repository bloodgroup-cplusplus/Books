/* imagine we have a class named license 
 * this class has a method named calcFee()
 * which is called by the billing applictaion
 * There are two subtypes of licenese personal license and business license 
 * They use different algorithms to calculate the license fee
 * -------------------				-----------------<I>---
						
 							LICENSE
 *  BILLING          ----------------->
 * -------------------				----------------------
 *  							+calcFee()
 *  						----------------------
 *
 *  							  ^
 *  							  |
 *  							  |
 *  					--------------
 *  					-
 *  					-
 *  					-
 *  					----------
 *  					Personal
 *  					License
 *  					--------           -  --- - - - -
 *  							  	  -
 *  							  	  -
 *  							  	  -
 *  							 ----------------
 *  							 	Business
 *  							 	License
 *  							 ----------------
 *  							 	- Users
 *  							 ----------------
 *this designe cconforms LSP because the behaviour of the Billing
 application doesnt depend in any way on which of the two subtypes it uses

