#pragma once

#include "CppSQLite3.h"

#include "Configuration.hpp"

namespace nejlika {

/**
 * @brief Represents a SQLite database connection.
 */
class Database
{
public:
    /**
     * @brief Constructs a new Database object.
     * 
     * @param path The path to the database SQLite file.
     * 
     * @throw If the database could not be opened.
     */
    Database(const std::string& path);

    /**
     * @brief Constructs a new Database object from another Database object.
     * 
     * @param other The other Database object.
     * 
     * @throw If the database could not be opened.
     */
    Database(const Database& other);

    /**
     * @brief Prepares an SQL statement for execution.
     *
     * @param query The SQL query to prepare.
     * @return A CppSQLite3Statement object representing the prepared statement.
     */
    CppSQLite3Statement Prepare(const std::string& query);
    
    /**
     * @brief Begins a transaction.
     */
    void BeginTransaction();

    /**
     * @brief Commits a transaction.
     */
    void CommitTransaction();
    
    /**
     * @brief Close the database connection.
     */
    void Close();

    /**
     * @brief Gets the path to the database SQLite file.
     * 
     * @return The path to the database SQLite file.
     */
    const std::string& GetPath() const;

    ~Database();

private:
    std::string m_Path;

    CppSQLite3DB m_Database;

    bool m_IsOpen = false;
};

} // namespace nejlika
