#include <iostream>
using namespace std;


class Num {
   int m_data;
public:
   Num(int data = 0) {
      m_data = data;
   }
   Num& operator= (int data){
      m_data = data;
      return *this;
   }
   ostream& display(ostream& ostr = cout)const {
      return ostr << m_data;
   }
};
ostream& operator<<(ostream& ostr, const Num& N) {
   return N.display(ostr);
}

class BoxedManupolator {
   ostream* m_ostr{};
public:
   BoxedManupolator& setOstream(ostream& ostr) {
      m_ostr = &ostr;
      return *this;
   }
   ostream& display(const Num& N) {
      if(m_ostr) {
         (*m_ostr) << "[" << N << "]";
      }
      return *m_ostr;
   }

} boxed;


BoxedManupolator& operator<<(ostream& ostr, BoxedManupolator& B) {
   return B.setOstream(ostr);
}

ostream& operator<<(BoxedManupolator& B, const Num& N) {
   return B.display(N);
}



int main() {
   Num N;
   N = 20;
   cout << N << endl;
   cout << boxed << N << endl;

   
   // [20]
   return 0;
}