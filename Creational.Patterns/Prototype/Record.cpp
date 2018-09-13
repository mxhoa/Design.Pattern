#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

// using namespace std;

/* Record is the base Prototype */
class Record
{
public:
    virtual ~Record() {}
    virtual void print() = 0;
    virtual std::unique_ptr<Record> clone() = 0;
};

/* CarRecord is a Concrete Prototype */
class CarRecord : public Record
{
private:
    std::string m_carName;
    int m_ID;

public:
    CarRecord(std::string carName, int ID) : m_carName(carName), m_ID(ID) {}

    void print() override
    {
        std::cout << "Car Record" << std::endl
                    << "Name    :" << m_carName << std::endl
                    << "Number  : " << m_ID << std::endl
                    << std::endl;
    }

    std::unique_ptr<Record> clone() override
    {
        return std::make_unique<CarRecord>(*this);
    }
};

/* BikeRecord is a Concrete Prototype */
class BikeRecord : public Record
{
private:
    std::string  m_bikeName;
    int     m_ID;

public:
    BikeRecord(std::string bikeName, int ID) : m_bikeName(bikeName), m_ID(ID) {}

    void print() override
    {
        std::cout << "Bike Record" << std::endl
                  << "Name    :" << m_bikeName << std::endl
                  << "Number  :" << m_ID << std::endl
                  << std::endl;
    }

    std::unique_ptr<Record> clone() override
    {
        return std::make_unique<BikeRecord>(*this);
    }
};

/* PersonRecord is a Concrete Prototype */
class PersonRecord : public Record 
{
private:
    std::string  m_personName;
    int     m_age;

public:
    PersonRecord(std::string personName, int age) : m_personName(personName), m_age(age) {}

    void print() override
    {
        std::cout << "Person Record" << std::endl
                  << "Name    :" << m_personName << std::endl
                  << "Age     :" << m_age << std::endl
                  << std::endl;
    }

    std::unique_ptr<Record> clone() override
    {
        return std::make_unique<PersonRecord>(*this);
    }
};
/* Opaque record type, avoids exposing concrete implementations */
enum RecordType
{
    CAR,
    BIKE,
    PERSON
};
/* RecordFactory is the client  */
class RecordFactory
{
private:
    std::unordered_map<RecordType, std::unique_ptr<Record>, std::hash<int>> m_records;
public:
    RecordFactory()
    {
        m_records[CAR]  = std::make_unique<CarRecord>("Ferrari", 5050);
        m_records[BIKE] = std::make_unique<BikeRecord>("Yamaha", 2525);
        m_records[PERSON] = std::make_unique<PersonRecord>("John", 27);
    }

    std::unique_ptr<Record> createRecord(RecordType recordType)
    {
        return m_records[recordType]->clone();
    }
};

int main()
{
    RecordFactory  recordFactory;

    auto record = recordFactory.createRecord(CAR);
    record->print();

    record = recordFactory.createRecord(BIKE);
    record->print();

    record = recordFactory.createRecord(PERSON);
    record->print();

    return 0;
}