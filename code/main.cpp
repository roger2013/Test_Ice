#include <Freeze/Freeze.h>
#include "MapByteSeq.h"
#include "MapFixedSeq.h"
#include "MapStringDouble.h"
#include "MapStringSeq.h"
#include <iostream>
#include <ctime>

using namespace std;

//calcola il tempo occorso per l'operazione richiesta
double calcola_differenza(clock_t fine, clock_t inizio){
	double difft = fine-inizio;
	double diffms = 1000*(difft)/(CLOCKS_PER_SEC);
	return diffms;
}

int main(int argc, char* argv[]){
	//inizializzo la connessione ice
	Ice::CommunicatorPtr communicator = Ice::initialize(argc,argv);

	//creo un freeze database
	Freeze::ConnectionPtr connection = Freeze::createConnection(communicator, "db");
	
	//inizializzo le mappe
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
	clock_t inizio = clock();
	//popolo la sequenza di byte
	for(Ice::Int i=0; i<100; i++){
		bSeq.clear();
		for(int k=0; k<Demo::ByteSeqSize; k++)
			bSeq.push_back((Ice::Byte)(i%256));
		mapByte.insert(make_pair(i,bSeq));
	}
	clock_t fine = clock();
	std::cout << "Scrittura 100 ByteSeq: " << calcola_differenza(fine,inizio) << std::endl;

	//leggo il db dei byteseq
	MapByteSeq::iterator p1;
	inizio = clock();
	for(p1=mapByte.begin(); p1!=mapByte.end(); ++p1)
		Demo::ByteSeq tmp = p1->second;
	fine = clock();
	std::cout << "Lettura 100 ByteSeq: " << calcola_differenza(fine,inizio) << std::endl << std::endl;

	//-----------FixedSeq--------------------------------------------------
	Demo::Fixed fix;
	inizio = clock();
	//popolo la sequenza di fixed
	for(Ice::Int i=0; i<100; ++i){
		fix.i = i;
		fix.j = i;
		fix.d = (Ice::Double)i;
		mapFixed.insert(make_pair(i,fix));
	}
	fine = clock();
	std::cout << "Scrittura 100 Fixed: " << calcola_differenza(fine,inizio) << std::endl;

	//leggo il db dei fixed
	MapFixedSeq::iterator p2;
	inizio = clock();
	for(p2=mapFixed.begin(); p2!=mapFixed.end(); ++p2)
		Demo::Fixed tmp = p2->second;
	fine = clock();
	std::cout << "Lettura 100 Fixed: " << calcola_differenza(fine,inizio) << std::endl << std::endl;

	//-----------StringDouble--------------------------------------------------
	Demo::StringDouble strdo;
	inizio = clock();
	//popolo la sequenza di stringdouble
	for(Ice::Int i=0; i<100; ++i){
		strdo.s = "prova";
		strdo.d = (Ice::Double)i;
		mapStrDo.insert(make_pair(i,strdo));
	}
	fine = clock();
	std::cout << "Scrittura 100 StringDouble: " << calcola_differenza(fine,inizio) << std::endl;

	//leggo il db dei stringdouble
	MapStringDouble::iterator p3;
	inizio = clock();
	for(p3=mapStrDo.begin(); p3!=mapStrDo.end(); ++p3)
		Demo::StringDouble tmp = p3->second;
	fine = clock();
	std::cout << "Lettura 100 StringDouble: " << calcola_differenza(fine,inizio) << std::endl << std::endl;

	//-----------StringSeq--------------------------------------------------
	Demo::StringSeq strs;
	inizio = clock();
	//popolo la sequenza di stringseq
	for(Ice::Int i=0; i<100; ++i){
		strs.clear();
		for (int k=0; k<Demo::StringSeqSize; k++)
			strs.push_back("prova");
		mapStr.insert(make_pair(i,strs));
	}
	fine = clock();
	std::cout << "Scrittura 100 StringSeq: " << calcola_differenza(fine,inizio) << std::endl;

	//leggo il db dei stringseq
	MapStringSeq::iterator p4;
	inizio = clock();
	for(p4=mapStr.begin(); p4!=mapStr.end(); p4++)
		Demo::StringSeq tmp = p4->second;
	fine = clock();
	std::cout << "Lettura 100 StringSeq: " << calcola_differenza(fine,inizio) << std::endl << std::endl;
}
