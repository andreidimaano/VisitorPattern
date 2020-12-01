#ifndef __COUNT_VISITOR_HPP__
#define __COUNT_VISITOR_HPP__

class CountVisitor{
    private:
        int ops;
        int rands;
        int mults;
        int divs;
        int add;
        int sub;
        int pow;

    public:

        CountVisitor(): ops(0), add(0), divs(0), pow(0){}


        CountVisitor(): ops(0), sub(0), add(0), divs(0){}

        void visit_op() {
            this->ops++;
        }
        int op_count() {
            return this->ops;
        }
        void visit_rand();
        int rand_count();
        void visit_mult();
        int mult_count();
        void visit_div(){
            this->divs++;
        }
        int div_count(){
            return this->divs;
        }
        void visit_add(){
	          this->add++;
	      }
        int add_count(){
	        return this->add;
	    }
        void visit_sub();
        int sub_count();
        void visit_pow() {
            this->pow++;
        }
        int pow_count(){
            return pow;
        }
	          return add;
	      }
        void visit_sub() {
	          this->sub++;
			  }
        int sub_count() {
            return this->sub; 
		    }
        void visit_pow();
        int pow_count();


};

#endif //__COUNT_VISITOR_HPP__
