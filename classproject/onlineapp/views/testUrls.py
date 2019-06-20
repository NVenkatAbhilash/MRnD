from django.http import *


def myFirstTestView(request):
    return HttpResponse("My First Response")