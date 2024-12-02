#include "Database.hpp"

#include <iostream>

using namespace nejlika;

nejlika::Database::Database(const std::string &path)
{
    m_Path = path;

    m_Database.open(path.c_str());

    // Check that the database is open.
    Prepare("SELECT 1;").execQuery();

    m_IsOpen = true;
}

nejlika::Database::Database(const Database &other)
{
    m_Path = other.m_Path;

    m_Database.open(m_Path.c_str());

    // Check that the database is open.
    Prepare("SELECT 1;").execQuery();

    m_IsOpen = true;
}

CppSQLite3Statement nejlika::Database::Prepare(const std::string &query)
{
    return m_Database.compileStatement(query.c_str());
}

void nejlika::Database::BeginTransaction()
{
    m_Database.execDML("BEGIN TRANSACTION");
}

void nejlika::Database::CommitTransaction()
{
    m_Database.execDML("COMMIT TRANSACTION");
}

void nejlika::Database::Close()
{
    if (!m_IsOpen)
    {
        return;
    }

    try
    {
        m_Database.close();
    }
    catch(CppSQLite3Exception& e)
    {
        std::cerr << CppSQLite3Exception::errorCodeAsString(e.errorCode()) << '\n' << e.errorMessage() << '\n';

        throw;
    }
    
}

const std::string &nejlika::Database::GetPath() const
{
    return m_Path;
}

nejlika::Database::~Database()
{
    Close();
}
