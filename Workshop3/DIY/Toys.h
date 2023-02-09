#ifndef SDDS_TOY_H
#define SDDS_TOY_H
#define MAX_TNAME 31 // define it to 31. The maximum length of a Toy name
namespace sdds
{
    class Toys
    {
    private:
        char m_tname[MAX_TNAME]; // toy name, up to MAX_TNAME size
        int m_sku;               // SKU number, maximum 8 digits long
        double m_price;          // toy price
        int m_age;               // toy according to age group
        bool m_onSale;           // keep track, if toys are on sale or not
    public:
        Toys();
        void addToys(const char *tname, int sku, double price, int age);
        void isSale(bool sale);
        void calSale();
        void display() const;
        bool compareSKU(int sku);
        void setEmpty();
    };
}
#endif