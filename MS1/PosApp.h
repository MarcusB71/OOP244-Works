/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 13/03/2023
*/

namespace sdds {
    class PosApp
    {
    private:
        char m_cstring[256];

    public:
        PosApp(const char* filename);
        PosApp(const PosApp& app) = delete;
        PosApp& operator=(const PosApp& app) = delete;
        int menu(); //displays menu and receives user choice must be valid int
        void addItem(); //print running and name
        void removeItem(); //print running and name
        void stockItem(); //print running and name
        void listItems(); //print running and name
        void POS(); //print running and name
        void saveRecs(); //print running and name
        void loadRecs(); //print running and name
        void run();
    };
}