from django.shortcuts import render
from onlineapp.models import *
# Create your views here.

from django.http import HttpResponse


def hello(request):
    str='<html><body><p>Hello</p></body></html>'
    return HttpResponse(str)


def get_my_college(request):
    return HttpResponse(College.objects.get(acronym='gvp').name)

def get_all_colleges(request):
    colleges=College.objects.all()
    return render(request,'college_table.html',{'colleges':colleges})


def college_students_info(request,num):
    college=College.objects.get(id=num)
    students=Student.objects.filter(college=college)
    return render(request,'student_table.html',{'students':students,'college':college})
