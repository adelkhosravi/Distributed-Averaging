//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/application/BGRC/BGRCPacket.msg.
//

#ifndef _BGRCPACKET_M_H_
#define _BGRCPACKET_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include "ApplicationPacket_m.h"
// }}

/**
 * Struct generated from src/node/application/BGRC/BGRCPacket.msg:7 by nedtool.
 */
struct BGRCData
{
    BGRCData();
    double yVal;
    double zVal;
};

void doPacking(cCommBuffer *b, BGRCData& a);
void doUnpacking(cCommBuffer *b, BGRCData& a);

/**
 * Class generated from <tt>src/node/application/BGRC/BGRCPacket.msg:12</tt> by nedtool.
 * <pre>
 * packet BGRCPacket extends ApplicationPacket
 * {
 *     BGRCData eData;
 * }
 * </pre>
 */
class BGRCPacket : public ::ApplicationPacket
{
  protected:
    BGRCData eData_var;

  private:
    void copy(const BGRCPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BGRCPacket&);

  public:
    BGRCPacket(const char *name=NULL, int kind=0);
    BGRCPacket(const BGRCPacket& other);
    virtual ~BGRCPacket();
    BGRCPacket& operator=(const BGRCPacket& other);
    virtual BGRCPacket *dup() const {return new BGRCPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual BGRCData& getEData();
    virtual const BGRCData& getEData() const {return const_cast<BGRCPacket*>(this)->getEData();}
    virtual void setEData(const BGRCData& eData);
};

inline void doPacking(cCommBuffer *b, BGRCPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, BGRCPacket& obj) {obj.parsimUnpack(b);}


#endif // ifndef _BGRCPACKET_M_H_

