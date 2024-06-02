class Gate
{
    public :
        Gate *input[2] ;
        virtual bool output() = 0 ;
  		void setValue(Gate *, int) ;
        void setValue(bool, int) ;
} ;

class TRUE : public Gate
{
    public :
        virtual bool output() { return 1 ; }
        void setValue(Gate *, int) {}
        void setValue(bool, int) {}
} ;

class FALSE : public Gate
{
    public :
        virtual bool output() { return 0 ; }
        void setValue(Gate *, int) {}
        void setValue(bool, int) {}
} ;

TRUE t ;
FALSE f ;

void Gate::setValue(bool val, int pin)
{
    if(val) this -> input[pin] = &t ;
    else this -> input[pin] = &f ;
}

void Gate::setValue(Gate *gate, int pin) { this -> input[pin] = gate ; }

class NOT : public Gate
{
    public :
        virtual bool output() { return !(this -> input[0] -> output()) ; }
        void setValue(bool val, int pin = 0)
        {
        	if(val) this -> input[0] = &t ;
            else this -> input[0] = &f ;
        }
        void setValue(Gate* gate, int pin = 0) { this -> input[0] = gate ; }
} ;

class NAND : public Gate
{
    public :
        virtual bool output() { return !(this -> input[0] -> output()) || !(this -> input[1] -> output()) ; }
} ;

class NOR : public Gate
{
    public :
        virtual bool output() { return !(this -> input[0] -> output()) && !(this -> input[1] -> output()) ; }
} ;

class AND : public Gate
{
    public :
        AND() : Gate() {
            component[0] = new NOT;
            component[1] = new NAND;
        }
        virtual bool output() {
            component[1] -> input[0] = this -> input[0] ;
            component[1] -> input[1] = this -> input[1] ;
            component[0] -> input[0] = component[1] ;
            return component[0] -> output() ;
        }
    private :
        Gate *component[2] ;
} ;

class OR : public Gate
{
    public :
        OR() : Gate() {
            component[0] = new NOT;
            component[1] = new NOR;
        }
        virtual bool output() {
            component[1] -> input[0] = this -> input[0] ;
            component[1] -> input[1] = this -> input[1] ;
            component[0] -> input[0] = component[1] ;
            return component[0] -> output() ;
        }
    private :
        Gate *component[2] ;
} ;

class XOR : public Gate // return ((a && !b) || (!a && b));
{
    public :
        XOR() : Gate() {
            component[0] = new NOT;
            component[1] = new NOT;
            component[2] = new AND;
            component[3] = new AND;
            component[4] = new OR;
        }
        virtual bool output() {
            component[0] -> input[0] = this -> input[0] ; // !a
            component[1] -> input[0] = this -> input[1] ; // !b
            component[2] -> input[0] = this -> input[0] ; // a && !b
            component[2] -> input[1] = component[1] ; 
            component[3] -> input[0] = this -> input[1] ; // !a && b
            component[3] -> input[1] = component[0] ;
            component[4] -> input[0] = component[2] ; // ((a && !b) || (!a && b))
            component[4] -> input[1] = component[3] ;
            return component[4] -> output() ;
        }
    private :
        Gate *component[5] ;
} ;

class Adder
{
    public :
        virtual void setValue(bool, int) = 0 ;
        virtual void setValue(Gate *, int) = 0 ;
        virtual Gate *sum() = 0 ;
        virtual Gate *carryOut() = 0 ;
} ;

class OneBitHalfAdder : public Adder
{
    public :
        OneBitHalfAdder() {
            component[0] = new AND;
            component[1] = new XOR;
        }
        virtual void setValue(bool val, int pin) {
            component[0] -> setValue(val, pin);
            component[1] -> setValue(val, pin);
        }
        virtual void setValue(Gate *gate, int pin) {
            component[0] -> setValue(gate, pin);
            component[1] -> setValue(gate, pin);
        }
        virtual Gate *sum() {
            return component[1]; // 1+1=10, carry is 1, sum is 0. 0+1=1, carry is 0, sum is 1.
        }
        virtual Gate *carryOut() {
            return component[0]; // look up
        }
    private :
        Gate *component[2] ;
} ;

class OneBitFullAdder : public Adder
{
    public :
        OneBitFullAdder() {
            a[0] = new OneBitHalfAdder;
            a[1] = new OneBitHalfAdder;
            carry = new OR;
        }
        virtual void setValue(bool val, int pin) {
            if(pin == 2) a[1] -> setValue(val, 1); // the 3rd pin is the 2nd pin of 2nd halfAdder
            else a[0] -> setValue(val, pin);
        }
        virtual void setValue(Gate *gate, int pin) {
            if(pin == 2) a[1] -> setValue(gate, 1);
            else a[0] -> setValue(gate, pin);
        }
        virtual Gate *sum() {
            a[1] -> setValue(a[0] -> sum(), 0); //get the first pin from 1st halfAdder
            return a[1] -> sum();
        }
        virtual Gate *carryOut() {
            a[1] -> setValue(a[0] -> sum(), 0);
            carry -> setValue(a[0] -> carryOut(), 0);
            carry -> setValue(a[1] -> carryOut(), 1);
            return carry;
        }
    private :
        Adder *a[2] ;
        Gate *carry ;
} ;
/* Reference example
class XNOR : public Gate
{
    public :
        XNOR() : Gate()
        {
            component[0] = new NOT ;
            component[1] = new XOR ;
        }
        virtual bool output()
        {
            component[1] -> input[0] = this -> input[0] ;
            component[1] -> input[1] = this -> input[1] ;
            component[0] -> input[0] = component[1] ;
            return component[0] -> output() ;
        }
    private :
        Gate *component[2] ;
} ;
*/
