#define MATHPLUS

//好用的位运算宏
#define mthpint(a) (a>>0)
#define mthpabs(a) ((a)>0?(a):(~a+1))
#define mthpmax(a,b) ((a)>(b)?(a):(b))
#define mthpmin(a,b) ((a)<(b)?(a):(b))
#define mthpminus(a) (~(a)+1)
#define mthpmul2n(a,b) ((a)<<(b))
#define mthpdiv2n(a,b) ((a)>>(b))
#define mthpmod2(a,b) ((a)&(b-1))


namespace mthp{

char a;

}