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
        CountVisitor():ops(0), sub(0) {}

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
        void visit_div();
        int div_count();
        void visit_add();
        int add_count();
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
