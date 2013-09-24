/***************************************************************************
    begin                : Sep 21 2013
    copyright            : (C) 2013 Mirko Montanari
    email                : 57454@studenti.unimore.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   and for public research institutes; you can redistribute it and/or    *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/

#include <Freeze/Freeze.h>
#include "MapByteSeq.h"
#include "MapFixedSeq.h"
#include "MapStringDouble.h"
#include "MapStringSeq.h"
#include <iostream>
#include <ctime>
#include <db.h>
#include <db_cxx.h>
#include <sys/stat.h>
#include <sys/time.h>

#define NCYCLES 100

using namespace std;

int main(int argc, char* argv[]){

	timeval start, stop;
	double elapsedTime;

	//initialize che Ice communicator
	Ice::CommunicatorPtr communicator = Ice::initialize(argc,argv);

	//create the Freeze's db with the BDB in disk
	Freeze::ConnectionPtr connection = Freeze::createConnection(communicator, "db");

	//create the Freeze's db on memory
	/*
	DbEnv env(0);
	u_int32_t flags = DB_INIT_LOG | DB_INIT_MPOOL | DB_INIT_TXN | DB_CREATE | DB_THREAD | DB_RECOVER | DB_INIT_LOCK | DB_LOCKDOWN | DB_SYSTEM_MEM | DB_PRIVATE;
	env.open("db", flags, S_IRUSR | S_IWUSR);
	Freeze::ConnectionPtr connection = Freeze::createConnection(communicator, "db",env);
	*/
	
	//initialize the maps
	MapByteSeq mapByte(connection, "ByteSeq");
	mapByte.clear();
	MapFixedSeq mapFixed(connection, "FixedSeq");
	mapFixed.clear();
	MapStringDouble mapStrDo(connection, "StringDouble");
	mapStrDo.clear();
	MapStringSeq mapStr(connection, "StringSeq");
	mapStr.clear();

	//---------ByteSeq----------------------------------------------------
	Demo::ByteSeq bSeq;
	gettimeofday(&start, NULL);
	//create the sequence of bye
	for(Ice::Int i=0; i<NCYCLES; i++){
		bSeq.clear();
		for(int k=0; k<Demo::ByteSeqSize; k++)
			bSeq.push_back((Ice::Byte)(i%256));
		mapByte.insert(make_pair(i,bSeq));
	}
	gettimeofday(&stop, NULL);
	elapsedTime = (stop.tv_sec - start.tv_sec) * 1000.0;
	elapsedTime += (stop.tv_usec - start.tv_usec) / 1000.0;
	std::cout << "Time for write one ByteSeq: " << elapsedTime/NCYCLES << " ms" << std::endl;

	//reade the byte's db
	MapByteSeq::iterator p1;
	gettimeofday(&start, NULL);
	for(p1=mapByte.begin(); p1!=mapByte.end(); ++p1)
		Demo::ByteSeq tmp = p1->second;
	gettimeofday(&stop, NULL);
	elapsedTime = (stop.tv_sec - start.tv_sec) * 1000.0;
	elapsedTime += (stop.tv_usec - start.tv_usec) / 1000.0;
	std::cout << "Time for read one ByteSeq: " << elapsedTime/NCYCLES << "ms" << std::endl << std::endl;

	//-----------FixedSeq--------------------------------------------------
	Demo::Fixed fix;
	gettimeofday(&start, NULL);
	//create the fixed's sequence and save in the db
	for(Ice::Int i=0; i<NCYCLES; ++i){
		fix.i = i;
		fix.j = i;
		fix.d = (Ice::Double)i;
		mapFixed.insert(make_pair(i,fix));
	}
	gettimeofday(&stop, NULL);
	elapsedTime = (stop.tv_sec - start.tv_sec) * 1000.0;
	elapsedTime += (stop.tv_usec - start.tv_usec) / 1000.0;
	std::cout << "Time for write one Fixed: " << elapsedTime/NCYCLES << "ms" << std::endl;

	//read the fixed's db
	MapFixedSeq::iterator p2;
	gettimeofday(&start, NULL);
	for(p2=mapFixed.begin(); p2!=mapFixed.end(); ++p2)
		Demo::Fixed tmp = p2->second;
	gettimeofday(&stop, NULL);
	elapsedTime = (stop.tv_sec - start.tv_sec) * 1000.0;
	elapsedTime += (stop.tv_usec - start.tv_usec) / 1000.0;
	std::cout << "Time for read one Fixed: " << elapsedTime/NCYCLES << "ms" << std::endl << std::endl;

	//-----------StringDouble--------------------------------------------------
	Demo::StringDouble strdo;
	gettimeofday(&start, NULL);
	//create the stringdouble sequence
	for(Ice::Int i=0; i<NCYCLES; ++i){
		strdo.s = "prova";
		strdo.d = (Ice::Double)i;
		mapStrDo.insert(make_pair(i,strdo));
	}
	gettimeofday(&stop, NULL);
	elapsedTime = (stop.tv_sec - start.tv_sec) * 1000.0;
	elapsedTime += (stop.tv_usec - start.tv_usec) / 1000.0;
	std::cout << "Time for write one StringDouble: " << elapsedTime/NCYCLES << "ms" << std::endl;

	//reade the stringdouble db
	MapStringDouble::iterator p3;
	gettimeofday(&start, NULL);
	for(p3=mapStrDo.begin(); p3!=mapStrDo.end(); ++p3)
		Demo::StringDouble tmp = p3->second;
	gettimeofday(&stop, NULL);
	elapsedTime = (stop.tv_sec - start.tv_sec) * 1000.0;
	elapsedTime += (stop.tv_usec - start.tv_usec) / 1000.0;
	std::cout << "Time for read one StringDouble: " << elapsedTime/NCYCLES << "ms" << std::endl << std::endl;

	//-----------StringSeq--------------------------------------------------
	Demo::StringSeq strs;
	gettimeofday(&start, NULL);
	//create the sequence of strings and insert into the db
	for(Ice::Int i=0; i<NCYCLES; ++i){
		strs.clear();
		for (int k=0; k<Demo::StringSeqSize; k++)
			strs.push_back("prova");
		mapStr.insert(make_pair(i,strs));
	}
	gettimeofday(&stop, NULL);
	elapsedTime = (stop.tv_sec - start.tv_sec) * 1000.0;
	elapsedTime += (stop.tv_usec - start.tv_usec) / 1000.0;
	std::cout << "Time for write one StringSeq: " << elapsedTime/NCYCLES << "ms" << std::endl;

	//read the stringseq's db
	MapStringSeq::iterator p4;
	gettimeofday(&start, NULL);
	for(p4=mapStr.begin(); p4!=mapStr.end(); p4++)
		Demo::StringSeq tmp = p4->second;
	gettimeofday(&stop, NULL);
	elapsedTime = (stop.tv_sec - start.tv_sec) * 1000.0;
	elapsedTime += (stop.tv_usec - start.tv_usec) / 1000.0;
	std::cout << "Time for read one StringSeq: " << elapsedTime/NCYCLES << "ms" << std::endl << std::endl;
}
