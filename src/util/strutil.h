#pragma once

#include <string>
#include <vector>

namespace asio_kcp {

std::wstring& CutSpace(std::wstring& ret);
std::string& CutSpace(std::string& ret);

std::string CutAllSpace(const std::string& srcStr);
// ��ȡ�ļ��ĺ�׺��
std::string GetFileSuffix(const std::string& fileName);

// ��ȡ�ļ��޺�׺���Ĳ���
//    ���� fsdf.txt  ��� fsdf
std::string GetFileWithoutSuffix(const std::string& fileName);

// ��ȡ�ļ���·����.
std::string GetFillPath_ByFullPathName(const std::string& fullPathName);

// ��ȡ ��·����Ϣ���ļ���
std::string GetFileNameWithoutPath(const std::string& fullPathName);

//����˵��
//���ܣ��ַ���תΪ����ֵ[�ַ�����Ϊ2-16]���������ֵ�ַ���
//���أ���������ֵ
//������strData Ϊ��Ҫת�����ַ���
//������jz Ϊ�ַ����Ľ���
long StrToData(const ::std::string& strData, int jz);

// ���ܣ� "�����ַ���" �� "c����ֻ���пɶ��ַ����ַ���(CStyleStr)" �໥ת��.
//
// "�����ַ���"	: �ַ����м�����������ַ�������NULL.
//
// CStyleStr	: �ַ����м�û��NULL,û�лس����У� ���ɼ��ַ�������ת��.
// ....... ���� ��123\(00)\r\n6786\t\(0d)\(0a)
//
// ��Ҫת����ַ���Χ��0 <= c < 0x20 �� c == 0x7F .
// ....... ����: 0x0d->\r, 0x0a->\n, , 0x09->\t; ������"\(ʮ����������)"�ķ�ʽת���ʾ
// ....... "\"������Ϊת��ָʾ����, �䱾����Ҫת��,��"\\"��ʽ��ʾ
//
::std::string ConvertToCStyleStr(const ::std::string& _Str); // ������BinaryStreamTester�� bufTester
::std::string ConvertFromCStyleStr(const ::std::string& _CStyleStr);

::std::string ToHexDumpText(const std::string& _Str, size_t width, const std::string& prefix = "!- ");

// ���ַ� '0'-'9'  'a'-'f'  'A'-'F' תΪ����Ӧ������.  A->10  B->11 f->15
int ToHexDigit(char c);

int CompairNoCase(const ::std::string& lhs, const ::std::string& rhs);
::std::string ToLower(const ::std::string& str);

} // namespace asio_kcp
