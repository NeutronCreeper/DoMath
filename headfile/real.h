#define REAL

#ifndef iostream
#include<iostream>
#endif
#ifndef STRUCTURE
#include "structure.h"
#endif
#ifndef RATIO
#include "ratio.h"
#endif

class real_single{
    private:
    ratio a,b;
    public:
    void set(const ratio& x,const ratio& y){
        a=x;
        b=y;
    };
    friend std::ostream& operator<<(std::ostream& output,const real_single& m){
        output<<'['<<m.a<<'^'<<m.b<<')';
        return output;
    };
    void operator=(const real_single& x){
        a=x.a;
        b=x.b;
    };
/*     void operator*=(real_single& x){
        real_single ans;
        ans.b=to_ratio(this->b.getq()*x.b.getq());
        ans.a.set(std::pow(this->a.getp(),this->b.getp()*x.b.getq()),this->a.getq()*x.a.getq());
        ans.a.simplify();
        ans.a.mul(std::pow(x.a.getp(),x.b.getp()*this->b.getq()));
        ans.a.simplify();
        
    }; */
    real_single operator*(real_single& x){
        real_single ans;
        ans.b=to_ratio(this->b.getq()*x.b.getq());
        ans.a.set(std::pow(this->a.getp(),this->b.getp()*x.b.getq()),this->a.getq()*x.a.getq());
        ans.a.simplify();
        ans.a.mul(std::pow(x.a.getp(),x.b.getp()*this->b.getq()));
        ans.a.simplify();
        return ans;
    };
    friend real_single real_single_create(const ratio& x,const ratio& y);
    friend real_single pow_real_single(real_single m,const ratio& n);
    //
};
real_single real_single_create(const ratio& x,const ratio& y){
    real_single ans;
    ans.a=x;
    ans.b=y;
    return ans;
};
real_single to_real_single(const ratio& m){
    return real_single_create(m,to_ratio(1));
};
real_single sqrt_ratio(const ratio& m){
    return real_single_create(m,ratio_create(1,2));
};
real_single pow_real_single(real_single m,const ratio& n){
    return real_single_create(m.a,m.b*n);
};