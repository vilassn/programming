#include <stdio.h>
#include <string>
#include <sqlite3.h> 
#include <stdexcept>
	

const std::string databaseTables[] =
{ 
" SourceClasses (sourceClassID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, name VARCHAR(50));",
" SinkClasses (sinkClassID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, name VARCHAR(50));", 
" Sources (sourceID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, domainID INTEGER, name VARCHAR(50), sourceClassID INTEGER, sourceState);",
" SystemProperties (type INTEGER PRIMARY KEY, value INTEGER);",
" volumeGrp (VolumeGrp INTEGER, muteState INTEGER, mainVolume INTEGER);",
" dummy(key INTEGER);"
};

class Demo
{
	sqlite3 *db;

	public:
		Demo()
		{
			char *zErrMsg = 0;
			int rc = sqlite3_open(":memory:", &db);

			if (rc)
				fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
			else
				fprintf(stderr, "Demo::Opened database successfully\n");

			for (int i = 0; i <  sizeof(databaseTables) / sizeof(databaseTables[0]); i++)
			{
				sqlite3_stmt* statement;
				int eCode = 0;
				if ((eCode = sqlite3_exec(db, ("CREATE TABLE " + databaseTables[i]).c_str(), NULL, &statement, NULL)) != SQLITE_OK)
				{
					throw std::runtime_error("Could not create tables!");
				}
			}
		}

		~Demo()
		{
			char *zErrMsg = 0;
			int rc = sqlite3_close(db);

			if (rc)
				fprintf(stderr, "Can't close database: %s\n", sqlite3_errmsg(db));
			else
				fprintf(stderr, "~Demo::Closed database successfully\n");
		}
};

int main(int argc, char* argv[])
{
	Demo obj;
}
