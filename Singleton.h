#pragma once
#ifndef __SINGLETON_H__
#define __SINGLETON_H__

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		if (!Instance)
		{
			Instance = new Singleton;
		}
		return *Instance;
	}

private:
	static Singleton* Instance;
};

#endif //__SINGLETON_H__