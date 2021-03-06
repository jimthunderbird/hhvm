/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2013 Facebook, Inc. (http://www.facebook.com)     |
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef incl_HPHP_EXT_SQLITE3_H_
#define incl_HPHP_EXT_SQLITE3_H_

#include <memory>
#include <vector>

#include <sqlite3.h>

#include "hphp/runtime/base/base-includes.h"
namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

extern const int64_t k_SQLITE3_ASSOC;
extern const int64_t k_SQLITE3_NUM;
extern const int64_t k_SQLITE3_BOTH;
extern const int64_t k_SQLITE3_INTEGER;
extern const int64_t k_SQLITE3_FLOAT;
extern const int64_t k_SQLITE3_TEXT;
extern const int64_t k_SQLITE3_BLOB;
extern const int64_t k_SQLITE3_NULL;
extern const int64_t k_SQLITE3_OPEN_READONLY;
extern const int64_t k_SQLITE3_OPEN_READWRITE;
extern const int64_t k_SQLITE3_OPEN_CREATE;

///////////////////////////////////////////////////////////////////////////////
// class SQLite3

FORWARD_DECLARE_CLASS(SQLite3);
class c_SQLite3 : public ExtObjectData {
 public:
  DECLARE_CLASS_NO_SWEEP(SQLite3)

  // need to implement
  public: c_SQLite3(Class* cls = c_SQLite3::classof());
  public: ~c_SQLite3();
  public: void t___construct(const String& filename, int64_t flags = k_SQLITE3_OPEN_READWRITE|k_SQLITE3_OPEN_CREATE, const String& encryption_key = null_string);
  public: void t_open(const String& filename, int64_t flags = k_SQLITE3_OPEN_READWRITE|k_SQLITE3_OPEN_CREATE, const String& encryption_key = null_string);
  public: bool t_busytimeout(int64_t msecs);
  public: bool t_close();
  public: bool t_exec(const String& sql);
  public: static Array ti_version();
  public: int64_t t_lastinsertrowid();
  public: int64_t t_lasterrorcode();
  public: String t_lasterrormsg();
  public: bool t_loadextension(const String& extension);
  public: int64_t t_changes();
  public: static String ti_escapestring(const String& sql);
  public: Variant t_prepare(const String& sql);
  public: Variant t_query(const String& sql);
  public: Variant t_querysingle(const String& sql, bool entire_row = false);
  public: bool t_createfunction(const String& name, CVarRef callback, int64_t argcount = -1);
  public: bool t_createaggregate(const String& name, CVarRef step, CVarRef final, int64_t argcount = -1);
  public: bool t_openblob(const String& table, const String& column, int64_t rowid, const String& dbname = null_string);


  public: void validate() const;
  public: sqlite3 *m_raw_db;
    struct UserDefinedFunc {
      int argc;
      Variant func;
      Variant step;
      Variant fini;
    };
  public: std::vector<std::shared_ptr<UserDefinedFunc>> m_udfs;
};

///////////////////////////////////////////////////////////////////////////////
// class SQLite3Stmt

FORWARD_DECLARE_CLASS(SQLite3Stmt);
class c_SQLite3Stmt : public ExtObjectData {
 public:
  DECLARE_CLASS_NO_SWEEP(SQLite3Stmt)

  // need to implement
  public: c_SQLite3Stmt(Class* cls = c_SQLite3Stmt::classof());
  public: ~c_SQLite3Stmt();
  public: void t___construct(CObjRef dbobject, const String& statement);
  public: int64_t t_paramcount();
  public: bool t_close();
  public: bool t_reset();
  public: bool t_clear();
  public: bool t_bindparam(CVarRef name, VRefParam parameter, int64_t type = k_SQLITE3_TEXT);
  public: bool t_bindvalue(CVarRef name, CVarRef parameter, int64_t type = k_SQLITE3_TEXT);
  public: Variant t_execute();



  public: void validate() const;
  public: p_SQLite3 m_db;
  public: sqlite3_stmt *m_raw_stmt;
    struct BoundParam {
      int type;
      int index;
      Variant value;
    };
  public: std::vector<std::shared_ptr<BoundParam>> m_bound_params;
};

///////////////////////////////////////////////////////////////////////////////
// class SQLite3Result

FORWARD_DECLARE_CLASS(SQLite3Result);
class c_SQLite3Result : public ExtObjectData {
 public:
  DECLARE_CLASS_NO_SWEEP(SQLite3Result)

  // need to implement
  public: c_SQLite3Result(Class* cls = c_SQLite3Result::classof());
  public: ~c_SQLite3Result();
  public: void t___construct();
  public: int64_t t_numcolumns();
  public: String t_columnname(int64_t column);
  public: int64_t t_columntype(int64_t column);
  public: Variant t_fetcharray(int64_t mode = k_SQLITE3_BOTH);
  public: bool t_reset();
  public: bool t_finalize();



  public: void validate() const;
  public: p_SQLite3Stmt m_stmt;
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // incl_HPHP_EXT_SQLITE3_H_
