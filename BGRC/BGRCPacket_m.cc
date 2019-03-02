//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/application/BGRC/BGRCPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "BGRCPacket_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

BGRCData::BGRCData()
{
    yVal = 0;
    zVal = 0;
}

void doPacking(cCommBuffer *b, BGRCData& a)
{
    doPacking(b,a.yVal);
    doPacking(b,a.zVal);
}

void doUnpacking(cCommBuffer *b, BGRCData& a)
{
    doUnpacking(b,a.yVal);
    doUnpacking(b,a.zVal);
}

class BGRCDataDescriptor : public cClassDescriptor
{
  public:
    BGRCDataDescriptor();
    virtual ~BGRCDataDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(BGRCDataDescriptor);

BGRCDataDescriptor::BGRCDataDescriptor() : cClassDescriptor("BGRCData", "")
{
}

BGRCDataDescriptor::~BGRCDataDescriptor()
{
}

bool BGRCDataDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BGRCData *>(obj)!=NULL;
}

const char *BGRCDataDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BGRCDataDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int BGRCDataDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *BGRCDataDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "yVal",
        "zVal",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int BGRCDataDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='y' && strcmp(fieldName, "yVal")==0) return base+0;
    if (fieldName[0]=='z' && strcmp(fieldName, "zVal")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BGRCDataDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *BGRCDataDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int BGRCDataDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BGRCData *pp = (BGRCData *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BGRCDataDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BGRCData *pp = (BGRCData *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->yVal);
        case 1: return double2string(pp->zVal);
        default: return "";
    }
}

bool BGRCDataDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BGRCData *pp = (BGRCData *)object; (void)pp;
    switch (field) {
        case 0: pp->yVal = string2double(value); return true;
        case 1: pp->zVal = string2double(value); return true;
        default: return false;
    }
}

const char *BGRCDataDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *BGRCDataDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BGRCData *pp = (BGRCData *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BGRCPacket);

BGRCPacket::BGRCPacket(const char *name, int kind) : ::ApplicationPacket(name,kind)
{
}

BGRCPacket::BGRCPacket(const BGRCPacket& other) : ::ApplicationPacket(other)
{
    copy(other);
}

BGRCPacket::~BGRCPacket()
{
}

BGRCPacket& BGRCPacket::operator=(const BGRCPacket& other)
{
    if (this==&other) return *this;
    ::ApplicationPacket::operator=(other);
    copy(other);
    return *this;
}

void BGRCPacket::copy(const BGRCPacket& other)
{
    this->eData_var = other.eData_var;
}

void BGRCPacket::parsimPack(cCommBuffer *b)
{
    ::ApplicationPacket::parsimPack(b);
    doPacking(b,this->eData_var);
}

void BGRCPacket::parsimUnpack(cCommBuffer *b)
{
    ::ApplicationPacket::parsimUnpack(b);
    doUnpacking(b,this->eData_var);
}

BGRCData& BGRCPacket::getEData()
{
    return eData_var;
}

void BGRCPacket::setEData(const BGRCData& eData)
{
    this->eData_var = eData;
}

class BGRCPacketDescriptor : public cClassDescriptor
{
  public:
    BGRCPacketDescriptor();
    virtual ~BGRCPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(BGRCPacketDescriptor);

BGRCPacketDescriptor::BGRCPacketDescriptor() : cClassDescriptor("BGRCPacket", "ApplicationPacket")
{
}

BGRCPacketDescriptor::~BGRCPacketDescriptor()
{
}

bool BGRCPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BGRCPacket *>(obj)!=NULL;
}

const char *BGRCPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BGRCPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int BGRCPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *BGRCPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "eData",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int BGRCPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "eData")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BGRCPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "BGRCData",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *BGRCPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int BGRCPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BGRCPacket *pp = (BGRCPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BGRCPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BGRCPacket *pp = (BGRCPacket *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getEData(); return out.str();}
        default: return "";
    }
}

bool BGRCPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BGRCPacket *pp = (BGRCPacket *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BGRCPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0: return opp_typename(typeid(BGRCData));
        default: return NULL;
    };
}

void *BGRCPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BGRCPacket *pp = (BGRCPacket *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getEData()); break;
        default: return NULL;
    }
}


