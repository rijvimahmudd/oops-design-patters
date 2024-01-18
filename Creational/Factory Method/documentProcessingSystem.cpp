/**
 * Design a document processing system that supports different document types (e.g., PDF, Word, Excel). Apply the Factory Method pattern to create document objects. Each document type should have a unique method, such as generateReport() for PDF and createSpreadsheet() for Excel.
 */

#include <bits/stdc++.h>
using namespace std;

class Document
{
public:
    virtual void generate() const = 0;
    virtual ~Document() = default;
};

class PDF : public Document
{
public:
    void generate() const override
    {
        generateReport();
    }

    void generateReport() const
    {
        cout << "pdf Report Generated" << endl;
    }
};

class Excel : public Document
{

public:
    void generate() const override
    {
        createSpreadsheet();
    }

    void createSpreadsheet() const
    {
        cout << "Excel Spreadsheet Created" << endl;
    }
};

class DocumentFactory
{

public:
    virtual Document *createDocument() = 0;
    virtual ~DocumentFactory() = default;
};

class PDFFactory : public DocumentFactory
{

public:
    Document *createDocument() override
    {
        return new PDF();
    }
};

class ExcelFactory : public DocumentFactory
{

public:
    Document *createDocument() override
    {
        return new Excel();
    }
};

int main(int argc, char const *argv[])
{
    DocumentFactory *pdfFactory = new PDFFactory();
    Document *pdf = pdfFactory->createDocument();
    pdf->generate();
    delete pdfFactory;
    delete pdf;

    DocumentFactory *excelFactory = new ExcelFactory();
    Document *excel = excelFactory->createDocument();
    excel->generate();
    delete excelFactory;
    delete excel;
    return 0;
}
