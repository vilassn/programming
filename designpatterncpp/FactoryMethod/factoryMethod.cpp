#include <stdio.h>
#include <string.h>
class CResource {
public:
  CResource() {}
  virtual ~CResource() {}
  virtual void printMessage () = 0;
};
template <class aResource>
class CResourceCreator {
public:
  virtual CResource* createResource ();
};

template <class aResource>
CResource* CResourceCreator<aResource>::createResource () {
  return new aResource;
}
class CPublicResource : public CResource {
public:
  CPublicResource() {}
  virtual ~CPublicResource() {}
  virtual void printMessage (void) {
    printf ("This is a Public Resource...\n");
  }
};
class CProfile {
public:
  CProfile(char* psName, char* psEmail) {
    if (psName) {
      m_psName = new char [strlen(psName)+1];
      strcpy (m_psName, psName);
    }
    if (psEmail) {
      m_psEmail = new char [strlen(psEmail)+1];
      strcpy (m_psEmail, psEmail);
    }
  }
  virtual ~CProfile() {
    delete [] m_psName;
    delete [] m_psEmail;
  }
  virtual char* getName (void) { return m_psName; }
  virtual char* getEmail (void) { return m_psEmail; }
  virtual bool  IsEmployee (void) { return m_bIsEmployee; }
  virtual CResource* getResource (void) = 0;
  
protected:
  char *m_psName;
  char *m_psEmail;
  bool m_bIsEmployee;
};
class CNonEmployee : public CProfile {
public:
  CNonEmployee (char* psName, char* psEmail) 
    :CProfile  (psName, psEmail) {
    m_bIsEmployee = false;
  }
  virtual ~CNonEmployee() {}
  virtual CResource* getResource (void) {
    CResourceCreator<CPublicResource> creator;
    return creator.createResource ();
  }
};

class CConfidentialResource : public CResource {
public:
  CConfidentialResource() {}
  virtual ~CConfidentialResource() {}
  virtual void printMessage (void) {
    printf ("This is a Company Confidential Resource...\n");
  }
};
class CEmployee : public CProfile {
public:
  CEmployee (char* psName, char* psEmail)
    : CProfile (psName, psEmail) {
    m_bIsEmployee = true;
  }
  virtual ~CEmployee() {}
  virtual CResource* getResource (void) {
    CResourceCreator<CConfidentialResource> creator;
    return creator.createResource ();
  }
};
int main(int argc, char* argv[]) {
  CEmployee employee ("Athul", "athul@eCommWare.com");
  CNonEmployee nonEmployee ("Aditya", "aditya@inventor.com");
  
  employee.getResource ()->printMessage ();
  nonEmployee.getResource ()->printMessage ();

  return 0;
}