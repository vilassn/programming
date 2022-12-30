// SmartWrapper.h: experimental implementation of "smart" wrapper objects

// for now assertions are placeholders
#define LOCAL_ASSERT(cond)

// "base" templates (right-most)

template <typename T>
class CTypeHolderT
{
protected:

	typedef	T TWrapped;	// for use by subclasses

	CTypeHolderT()
	{
	}

	T Get() const
	{
		return m_T;
	}

	T& GetRef()
	{
		return m_T;
	}

	const T& GetConstRef() const
	{
		return m_T;
	}

	T* GetPointer()
	{
		return &m_T;
	}

	void Assign(const T& rT)
	{
		m_T = rT;
	}

private:

	T m_T;
};

template <typename T>
class CTypeInheritorT : public T
{
protected:
	typedef T TWrapped;	// for use by subclasses

	CTypeInheritorT()
	{
	}

	T Get() const
	{
		return *this;
	}

	T& GetRef()
	{
		return *this;
	}

	const T& GetConstRef() const
	{
		return *this;
	}

	T* GetPointer()
	{
		return this;
	}
};

// decorator templates (intermediate)

template <typename TInitPolicy, typename T>
class CInitT : public T
{
protected:
	CInitT()
	{
		TInitPolicy::Init(GetRef());
	}
};

template <class TShallowCopyPolicy, typename T>
class CShallowCopyableT : public T
{
protected:
	CShallowCopyableT() {}

	void SetShallow(const T::TWrapped& rT)
	{
		InternalShallowCopy(GetRef(), rT);
	}
	static void InternalShallowCopy(T::TWrapped& rDst, const T::TWrapped& rSrc)
	{
		TShallowCopyPolicy::Copy(rDst, rSrc);
	}
};

template <class TDeepCopyPolicy, typename T>
class CDeepCopyableT : public T
{
protected:
	CDeepCopyableT() {}

	void SetDeep(const T::TWrapped& rT)
	{
		InternalDeepCopy(GetRef(), rT);
	}
	static void InternalDeepCopy(T::TWrapped& rDst, const T::TWrapped& rSrc)
	{
		TDeepCopyPolicy::Copy(rDst, rSrc);
	}
};

template <class TInvalidationPolicy, typename T>
class CInvalidatableT : public T
{
public:
	bool IsValid() const
	{
		return TInvalidationPolicy::IsValid(GetConstRef());
	}

	void SetInvalid()
	{
		TInvalidationPolicy::SetInvalid(GetRef());
	}
};

template <class TDestroyPolicy, typename T>
class CDestroyableT : public T
{
public:
	void Destroy()
	{
		if (IsValid())
		{
			TDestroyPolicy::Destroy(GetRef());
			SetInvalid();
		}
	}

protected:
	CDestroyableT()
	{
		SetInvalid();
	}
};

template <class T>
class CAttachableT : public T
{
public:
	void Attach(const T::TWrapped& rT)
	{
		Destroy();
		SetShallow(rT);
	}

	T::TWrapped Detach()
	{
		T temp = Get();
		Destroy();
		return temp;
	}

protected:
	CAttachableT() {}
};

template <class T>
class CDefCtorT : public T
{
protected:
	CDefCtorT()				{}
	void InternalDefCtor()	{}
};

template <class T>
class CCopyCtorShallowT : public T
{
protected:
	CCopyCtorShallowT() {}

	void InternalCopyCtor(const T::TWrapped& rT)
	{
		InternalShallowCopy(GetRef(), rT);
	}
};

template <class T>
class CCopyCtorDeepT : public T
{
protected:
	CCopyCtorDeepT() {}

	void InternalCopyCtor(const T::TWrapped& rT)
	{
		InternalDeepCopy(GetRef(), rT);
	}
};

template <class T>
class CTCtorShallowT : public T
{
protected:
	CTCtorShallowT() {}

	void InternalTCtor(const T::TWrapped& rT)
	{
		InternalShallowCopy(GetRef(), rT);
	}
};

template <class T>
class CTCtorDeepT : public T
{
protected:
	CTCtorDeepT() {}

	void InternalTCtor(const T::TWrapped& rT)
	{
		InternalDeepCopy(GetRef(), rT);
	}
};

template <class T>
class COperatorT : public T
{
protected:
	COperatorT() {}
public:

	operator T::TWrapped() const
	{
		LOCAL_ASSERT(IsValid());
		return Get();
	}
};

template <class T>
class CAutoDestroyT : public T
{
protected:
	CAutoDestroyT()		{}
public:
	~CAutoDestroyT()	{ Destroy(); }
};

// generic "policy" implementations

template <typename T>
class CInitZeroMemoryT
{
public:
	static void Init(T& rT)
	{
		::ZeroMemory(&rT, sizeof(T));
	}
private:
	CInitZeroMemoryT();
	CInitZeroMemoryT(const CInitZeroMemoryT&);
};

template <typename T>
class CInitZeroSetCBSizeT
{
public:
	static void Init(T& rT)
	{
		::ZeroMemory(&rT, sizeof(T));
		rT.cbSize = sizeof(T);
	}
private:
	CInitZeroSetCBSizeT();
	CInitZeroSetCBSizeT(const CInitZeroSetCBSizeT&);
};

class CFail
{
private:
	CFail();
	CFail(const CFail&);
};

typedef CFail CCopyDisallowed;

template <typename T>
class CCopyByAssignmentT
{
public:
	static void Copy(T& rDst, const T& rSrc)
	{
		rDst = rSrc;
	}
private:
	CCopyByAssignmentT();
	CCopyByAssignmentT(const CCopyByAssignmentT&);
};

template <typename T>
class CAlwaysValidT
{
public:
	static bool IsValid(const T& rT)
	{
		return true;
	}
	static void SetInvalid(T& rT)
	{
	}
private:
	CAlwaysValidT();
	CAlwaysValidT(const CAlwaysValidT&);
};

template <typename T, T TInvalidValue>
class CInvalidValueT
{
public:
	static bool IsValid(const T& rT)
	{
		return rT != TInvalidValue;
	}
	static void SetInvalid(T& rT)
	{
		rT = TInvalidValue;
	}
private:
	CInvalidValueT();
	CInvalidValueT(const CInvalidValueT&);
};

template <typename T, typename U, U UInvalidValue>
class CInvalidValueWithStaticCastT
{
public:
	static bool IsValid(const T& rT)
	{
		return rT != static_cast<T>(UInvalidValue);
	}
	static void SetInvalid(T& rT)
	{
		rT = static_cast<T>(UInvalidValue);
	}
private:
	CInvalidValueWithStaticCastT();
	CInvalidValueWithStaticCastT(const CInvalidValueWithStaticCastT&);
};

template <typename T, typename U, U UInvalidValue>
class CInvalidValueWithReinterpretCastT
{
public:
	static bool IsValid(const T& rT)
	{
		return rT != reinterpret_cast<T>(UInvalidValue);
	}
	static void SetInvalid(T& rT)
	{
		rT = reinterpret_cast<T>(UInvalidValue);
	}
private:
	CInvalidValueWithReinterpretCastT();
	CInvalidValueWithReinterpretCastT(const CInvalidValueWithReinterpretCastT&);
};

// "client" templates (left-most)

template <class T>
class CWrapperT : public T
{
public:
	CWrapperT()
	{
		// call marker method to ensure validity
		InternalDefCtor();
	}

	CWrapperT(const CWrapperT<T>& rThis)
	{
		// implement via decorator template method
		InternalCopyCtor(rThis.GetConstRef());
	}

	CWrapperT(const T::TWrapped& rT)
	{
		// implement via decorator template method
		InternalTCtor(rT);
	}
};

template <class T>
class CWrapperExT : public T
{
public:
	CWrapperExT()
	{
		// call marker method to ensure validity
		InternalDefCtor();
	}

	template <typename T1>
	CWrapperExT(T1 p1)
	{
		// implement via type-specific method
		InternalOtherCtor(p1);
	}

	template<>
	CWrapperExT(const CWrapperT<T>& rThis)
	{
		// implement via decorator template method
		InternalCopyCtor(rThis.GetConstRef());
	}

	template<>
	CWrapperExT(const T::TWrapped& rT)
	{
		// implement via decorator template method
		InternalTCtor(rT);
	}

	template <typename T1, typename T2>
	CWrapperExT(T1 p1, T2 p2)
	{
		// implement via type-specific method
		InternalOtherCtor(p1, p2);
	}

	template <typename T1, typename T2, typename T3>
	CWrapperExT(T1 p1, T2 p2, T3 p3)
	{
		// implement via type-specific method
		InternalOtherCtor(p1, p2, p3);
	}
};

// other utility templates

template <class T>
class CAcquirerT
{
// NOTE:	the acquirer itself is not thread-safe, as it is only intended to be used
//			as a local object
public:
	CAcquirerT(T& rSyncObj, bool bAcquireNow = true)
		: m_rSyncObj(rSyncObj)
		, m_cAcquisitions(0)
	{
		if (bAcquireNow)
			Acquire();
	}

	~CAcquirerT()
	{
		while (IsHeld())
		{
			if (!Release())
				break;
		}
	}

	bool Acquire()
	{
		if (m_rSyncObj.Acquire())
		{
			++m_cAcquisitions;
			return true;
		}

		return false;
	}

	bool Acquire(DWORD dwTimeoutMS)
	{
		if (m_rSyncObj.Acquire(dwTimeoutMS))
		{
			++m_cAcquisitions;
			return true;
		}

		return false;
	}

	bool Release()
	{
		LOCAL_ASSERT(m_cAcquisitions > 0);

		if (m_cAcquisitions <= 0)
			return false;

		if (m_rSyncObj.Release())
		{
			--m_cAcquisitions;
			return true;
		}

		return false;
	}

	bool IsHeld() const
	{
		return m_cAcquisitions > 0;
	}

private:
	T&		m_rSyncObj;
	DWORD	m_cAcquisitions;
};

// type-specific "policy" implementation

class CCloseHandle
{
public:
	static void Destroy(HANDLE& rh)
	{
		BOOL bOK = ::CloseHandle(rh);
		LOCAL_ASSERT(FALSE != bOK); bOK;
	}
private:
	CCloseHandle();
	CCloseHandle(const CCloseHandle&);
};

class CDuplicateHandle
{
public:
	static void Copy(HANDLE& rDst, const HANDLE& rSrc)
	{
		BOOL bOK = ::DuplicateHandle(::GetCurrentProcess(), rSrc,
									 ::GetCurrentProcess(), &rDst,
									 0, false, DUPLICATE_SAME_ACCESS);
		LOCAL_ASSERT(FALSE != bOK); bOK;
	}
private:
	CDuplicateHandle();
	CDuplicateHandle(const CDuplicateHandle&);
};

class CInitCritSec
{
public:
	static void Init(CRITICAL_SECTION& rcs)
	{
		::InitializeCriticalSection(&rcs);
	}
private:
	CInitCritSec();
	CInitCritSec(const CInitCritSec&);
};

class CDeleteCritSec
{
public:
	static void Destroy(CRITICAL_SECTION& rcs)
	{
		::DeleteCriticalSection(&rcs);
	}
private:
	CDeleteCritSec();
	CDeleteCritSec(const CDeleteCritSec&);
};

// wrapper implementations

typedef CDestroyableT		< CCloseHandle,
		CDeepCopyableT		< CDuplicateHandle,
		CInvalidatableT		< CInvalidValueT< HANDLE , NULL >,
		CShallowCopyableT	< CCopyByAssignmentT< HANDLE >,
		CTypeHolderT		< HANDLE > > > > >

		CHandleWrapperImpl;

typedef		CWrapperT
		<	COperatorT
		<	CDefCtorT
		<	CTCtorShallowT
		<	CHandleWrapperImpl > > > > CHandleWrapper;

#define INVALID_HANDLE_INTEGER -1	// TODO: add compile time checking for consistency

typedef CDestroyableT		< CCloseHandle,
		CDeepCopyableT		< CDuplicateHandle,
		CInvalidatableT		< CInvalidValueWithReinterpretCastT< HANDLE , int , INVALID_HANDLE_INTEGER >,
		CShallowCopyableT	< CCopyByAssignmentT< HANDLE >,
		CTypeHolderT		< HANDLE > > > > >

		CFileHandleWrapperImpl;

typedef		CWrapperT
		<	COperatorT
		<	CDefCtorT
		<	CTCtorShallowT
		<	CFileHandleWrapperImpl > > > > CFileHandleWrapper;

typedef		CWrapperT
		<	CAutoDestroyT
		<	COperatorT
		<	CDefCtorT
		<	CCopyCtorDeepT
		<	CTCtorDeepT
		<	CFileHandleWrapperImpl > > > > > > CAutoDeepFileHandleWrapper;

class CCriticalSectionImpl : public
	CAutoDestroyT	<
	CDefCtorT		<
	CDestroyableT	< CDeleteCritSec,
	CInvalidatableT	< CAlwaysValidT< CRITICAL_SECTION >,
	CInitT			< CInitCritSec,
	CTypeHolderT	< CRITICAL_SECTION > > > > > >
{
private:
	friend class CAcquirerT<CWrapperT<CCriticalSectionImpl> >;

	bool Acquire()
	{
		::EnterCriticalSection(GetPointer());
		return true;
	}

	bool Release()
	{
		::LeaveCriticalSection(GetPointer());
		return true;
	}
};

typedef CWrapperT<CCriticalSectionImpl> CCriticalSection;

class CMutexImpl;

typedef CWrapperExT<CMutexImpl> CMutex;

typedef CAutoDestroyT		<
		CDestroyableT		< CCloseHandle,
		CInvalidatableT		< CInvalidValueT< HANDLE , NULL >,
		CShallowCopyableT	< CCopyByAssignmentT< HANDLE >,
		CTypeHolderT		< HANDLE > > > > >
					
		CMutexBase;

enum EWaitResult
{
	WaitTimedOut	= WAIT_TIMEOUT
,	WaitAbandoned	= WAIT_ABANDONED
,	WaitSucceeded0	= WAIT_OBJECT_0
};

class CMutexImpl : private CMutexBase
{
public:
	EWaitResult WaitResult()
	{
		return m_WaitResult;
	}

	using CMutexBase::IsValid;

protected:

	using CMutexBase::TWrapped;

	void InternalOtherCtor(LPCTSTR tszName, BOOL bInitialOwner = FALSE,
		   LPSECURITY_ATTRIBUTES lpsa = NULL)
	{
		SetShallow(::CreateMutex(lpsa, bInitialOwner, tszName));
	}

private:
	friend class CAcquirerT<CMutex>;

	bool Acquire(DWORD dwTimeoutMS = INFINITE)
	{
		LOCAL_ASSERT(IsValid());

		if (!IsValid())
			return false;

		m_WaitResult =
			static_cast<EWaitResult>(::WaitForSingleObject(Get(), dwTimeoutMS));

		return m_WaitResult != WaitTimedOut;
	}

	bool Release()
	{
		LOCAL_ASSERT(IsValid());

		if (!IsValid())
			return false;

		BOOL bOK = ::ReleaseMutex(Get());

		LOCAL_ASSERT(FALSE != bOK);

		return FALSE != bOK;
	}

	EWaitResult m_WaitResult;
};

#include <ShellApi.h>

class CNotifyIconData : public
	CInitT			< CInitZeroSetCBSizeT < NOTIFYICONDATA >,
	CTypeInheritorT	< NOTIFYICONDATA > >
{
};
