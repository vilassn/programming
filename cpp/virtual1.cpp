#include <iostream>
using namespace std;

class MediaPlayer
{
 private:
 	int duration;

 public:
	MediaPlayer()
	{
	 cout<<"In "<<__func__<<"()"<<endl;
	}

	void start() //can be used by derived class as it is, no need to define again in derived class
	{
	 cout<<"In "<<__func__<<", MediaPlayer"<<endl;
	}

	virtual	void play() //you may or may not need to define it in derived class
	{
	 cout<<"In "<<__func__<<", MediaPlayer"<<endl;
	}

	virtual void stop()=0; //you must define it in derived class if you are creating derived class obj

	~MediaPlayer()
	{
	 cout<<"In "<<__func__<<"()"<<endl;
	}
};

class CDPlayer: public MediaPlayer
{
 public:
	CDPlayer()
	{
	 cout<<"In "<<__func__<<"()"<<endl;
	}

	void start()
	{
	 cout<<"In "<<__func__<<", CDPlayer"<<endl;
	}

 	void play()
	{
	 cout<<"In "<<__func__<<", CDPlayer"<<endl;
	}

 	void stop()
	{
	 cout<<"In "<<__func__<<", CDPlayer"<<endl;
	}

	~CDPlayer()
	{
	 cout<<"In "<<__func__<<"()"<<endl;
	}

	virtual	void play2()
	{
	 cout<<"In "<<__func__<<", CDPlayer"<<endl;
	}
};

class DVDPlayer
{

};

int main()
{
 CDPlayer cdp;

 cdp.start();
 cdp.play();
 cdp.stop();
 cout<<endl;
 
 MediaPlayer *mp; 
 mp=&cdp;
 mp->start();//calling mediaplayer::start()
 mp->play(); //calling CDPlayer::play()
 mp->stop(); //calling CDPlayer::stop()

 return 0;
}
