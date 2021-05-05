#include "databaseLogger.h"
namespace loggers{
    DatabaseLogger::DatabaseLogger() {
        if(sqlite3_open("D:\\AGH\\WEAIiIB\\2 semestr\\PP2\\Laboratorium9\\logowania_db.db", &db)){
            throw std::invalid_argument("Can't open database file logowania_db");
        }
    }
    DatabaseLogger::~DatabaseLogger() {
        sqlite3_close(db);
    }

    static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
        int i;
        for(i = 0; i<argc; i++) {
            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        }
        printf("\n");
        return 0;
    }

    char *zErrMsg = 0;

    void DatabaseLogger::log(std::string text){
        std::string sqlQuery = "CREATE TABLE IF NOT EXISTS Log("  \
                      "LoggingTime    TEXT    NOT NULL," \
                      "Message        TEXT    NOT NULL);";
        if(sqlite3_exec(db,sqlQuery.c_str(), callback, 0, &zErrMsg) != SQLITE_OK){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            throw std::invalid_argument("Error when creating a table");
            sqlite3_free(zErrMsg);
        };

        sqlQuery = "INSERT INTO Log (LoggingTime, Message) VALUES (\""
                   + getCurrentTimeInTextForm() + "\", \"" + text + "\")";
        if(sqlite3_exec(db,sqlQuery.c_str(), callback, 0, &zErrMsg) != SQLITE_OK){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            throw std::invalid_argument("Error when writing to database");
            sqlite3_free(zErrMsg);
        };

    }
    Logger& DatabaseLogger::instance(){
        static DatabaseLogger singleton;
        return singleton;
    }
}