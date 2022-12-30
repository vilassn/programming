#include<iostream.h>
class CFiller
{
public:
	virtual void DoFill()=0;
};

class RtoLFiller : public CFiller
{
public:
	void DoFill()
	{
		cout<<"Right to Left Filler";
	}
};

class LtoRFiller : public CFiller
{
public:
	void DoFill()
	{
		cout<<"Left to Right Filler";
	}
};

// Class declaration for CProgressIndicator
class CProgressIndicator
{
    // Method declarations
    public:
        CProgressIndicator(CFiller *);
        void SetPos(int);
        int SetFiller(CFiller *);
            
    // Data members
    protected:
        CFiller * m_pFiller;
};

// CProgressIndicator - Implementation
CProgressIndicator ::CProgressIndicator(CFiller * pFiller)
{
    // Validate pFiller 
    m_pFiller = pFiller;
}

void CProgressIndicator ::SetPos(int nPos)
{
    // Some initialization code before forwarding the request to filler object
       
       
// Request forwarding to filler object
    m_pFiller->DoFill();
      
      

}

int  CProgressIndicator ::SetFiller(CFiller * pFiller)
{
    
        // Set new filler object
    m_pFiller = pFiller;
    return 0;
}

int main()
{
	CFiller *f = new RtoLFiller;
CProgressIndicator pi(f);
pi.SetPos(5);

return 0;
}

