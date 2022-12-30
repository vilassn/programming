#include<iostream.h>
class CBaseState
{
public:
    // Pure virtual function
    virtual CBaseState* GetNextState() = 0;
	virtual void disp()=0;
    // print the string
    
};

//////////////////////////////////////////////////////////////////////////
// State Morning
//////////////////////////////////////////////////////////////////////////
class CMorning : public CBaseState
{
public:
    virtual CBaseState* GetNextState();
	void disp();
    
};

//////////////////////////////////////////////////////////////////////////
// State Evening
//////////////////////////////////////////////////////////////////////////
class CEvening : public CBaseState
{
public:
    virtual CBaseState* GetNextState();
	void disp();
    
};

//////////////////////////////////////////////////////////////////////////
// State night
//////////////////////////////////////////////////////////////////////////
class CNight: public CBaseState
{
public:
    virtual CBaseState* GetNextState();
	void disp();
    
};

//////////////////////////////////////////////////////////////////////////
// Context Class
//////////////////////////////////////////////////////////////////////////

class CSun
{
public:
    CSun();
    CSun(CBaseState* pContext /* Pass Allocated memory */);
    
    // Handles the next state
    void StateChanged();
    //char* GetStateName();
protected:
    void DoCleanUp();
    // Pointer which holds the current state
    // Since this is and base class pointer
    // of Concentrate classes, it can holds their objects
    CBaseState* m_pState;
};
void CSun::StateChanged()
{
    if (m_pState)
    {
        // Getting Next State
        CBaseState* pState = m_pState->GetNextState();
        // de allocates the memory
        delete m_pState;
          m_pState = pState;
    }
}
CSun::CSun(CBaseState *b)
{
	m_pState=b;
}

CBaseState* CMorning::GetNextState()
{
    return new CEvening;
}

void CMorning::disp()
{
    cout<<"This is Morning";
}
CBaseState* CEvening::GetNextState()
{
    return new CNight;
}

void CEvening::disp()
{
    cout<<"This is Evening";
}

CBaseState* CNight::GetNextState()
{
    return new CMorning;
}

void CNight::disp()
{
    cout<<"This is Night";
}

int main()
{
CSun objSun(new CMorning);
/*cout<<"\n\nSun Says Good"<<objSun.GetStateName();
// inform that state has been changed
objSun.StateChanged();
cout<<"\n\nSun Says Good "<<objSun.GetStateName();
// inform that state has been changed
objSun.StateChanged();
cout<<"\n\nSun Says Good "<<objSun.GetStateName();
// inform that state has been changed
objSun.StateChanged();	
cout<<"\n\nSun Says Good "<<objSun.GetStateName();*/

	return 0;
}