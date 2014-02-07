module Demo
{

sequence<byte> ByteSeq;
const int ByteSeqSize = 128000;

sequence<string> StringSeq;
const int StringSeqSize = 128000;

struct StringDouble
{
string s;
double d;
};
sequence<StringDouble> StringDoubleSeq;
const int StringDoubleSeqSize = 128000;

struct Fixed
{
int i;
int j;
double d;
};
sequence<Fixed> FixedSeq;

sequence<float> FloatSeq;
const int FloatSeqSize = 120;

sequence<double> DoubleSeq;
const int DoubleSeqSize = 120;


class UserDataT
{
string username;
double ru;
};

class complexKey

{

double time;

double ra;

float dec;

float energy;

};

sequence< complexKey > ComplexKeySeq;
const int ComplexSeqSize = 120;


};


































































