#pragma once

/*
*      Copyright (C) 2005-2013 Team Kodi
*      http://kodi.tv
*
*  This Program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2, or (at your option)
*  any later version.
*
*  This Program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with XBMC; see the file COPYING.  If not, see
*  <http://www.gnu.org/licenses/>.
*
*/

#include <string>
#include <vector>

class IInputCodingTable
{
public:
  enum { TYPE_WORD_LIST, TYPE_CONVERT_STRING };
  virtual int GetType() { return TYPE_WORD_LIST; }

  virtual ~IInputCodingTable() {}
  virtual bool GetWordListPage(const std::string& strCode, bool isFirstPage) = 0;
  virtual std::vector<std::wstring> GetResponse(int response) = 0;
  const std::string& GetCodeChars() const { return m_codechars; }

  virtual void SetTextPrev(const std::string& strTextPrev) {}
  virtual std::string ConvertString(const std::string& strCode) { return std::string(""); }

protected:
  std::string m_codechars;
};
