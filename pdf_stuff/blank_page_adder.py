
import os, PyPDF2

base_doc = input("enter filepath of the file needing an appending: ")

pre_pivot = int(input("After which page would you like to insert a blank page: "))



pdf_base_file = open(base_doc, 'rb')
#@BUG Figure out how to create a true Blank page pdf here in source code, so that
#       this script doesn't depend on one's existence prior to running
#       pdf_blank_page = open(os.path.join(os.path.dirname(base_doc), "Blankie.pdf"), 'wb')
#@BUG: tried to use the above line, with the 'wb' instead of 'rb', assuming I could simply write the file, but the file is dogshit when I do
pdf_blank_page = open(os.path.join(os.path.dirname(base_doc), "Blank.pdf"), 'rb')

base_file_reader = PyPDF2.PdfFileReader(pdf_base_file)
blank_page_reader = PyPDF2.PdfFileReader(pdf_blank_page)
pdfWriter = PyPDF2.PdfFileWriter()

for pageNum in range(pre_pivot):
    pageObj = base_file_reader.getPage(pageNum)
    pdfWriter.addPage(pageObj)

for pageNum in range(blank_page_reader.numPages):
    pageObj = blank_page_reader.getPage(pageNum)
    pdfWriter.addPage(pageObj)

for pageNum in range(pre_pivot, base_file_reader.numPages):
    pageObj = base_file_reader.getPage(pageNum)
    pdfWriter.addPage(pageObj)


new_file_name = base_doc[:(len(base_doc) - 4)] + "_with_blank.pdf"

pdfOutputFile = open(new_file_name, 'wb')
pdfWriter.write(pdfOutputFile)
pdfOutputFile.close()
pdf_base_file.close()
pdf_blank_page.close()

