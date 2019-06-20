from django.contrib.auth import authenticate, login
from django.contrib.auth.models import User
from django.shortcuts import render, redirect

# Create your views here.
from django.views import View

from todoapp.forms.signUpLoginForm import LoginForm, SignupForm
from todoapp.models import *


class ItemsView(View):
    def get(self,request,*args,**kwargs):
        list = Todolist.objects.get(**kwargs)
        items = Todoitem.objects.filter(list = list)
        return render(
            request,
            template_name='todoitems.html',
            context={'items': items},
        )

class ListView(View):
    def get(self,request):
        list = Todolist.objects.all()
        return render(
            request,
            template_name='todolist.html',
            context={'list':list},
        )


class LoginController(View):
    def get(self,request,*args,**kwargs):
        login = LoginForm()
        return render(
            request,
            template_name='loginSignup.html',
            context={'form':login,'title':'Login','link_name':'signup'}
        )
    def post(self,request,*args,**kwargs):
        loginForm = LoginForm(request.POST)
        if loginForm.is_valid():
            user = authenticate(
                request,
                username = loginForm.cleaned_data['username'],
                password=loginForm.cleaned_data['password']
            )
            if user is not None:
                login(request,user)
                return redirect('colleges.url')
        #messages.error(request,'username or password not correct')
        return render(
            request,
            template_name='loginSignup.html',
            context={'form':loginForm,'title':'Login','link_name':'signup','message':'invalid credentials'}
        )

class SignupController(View):
    def get(self,request,*args,**kwargs):
        form = SignupForm()
        return render(
            request,
            template_name='loginSignup.html',
            context={'form':form,'title':'Signin','link_name':'login'}
        )
    def post(self,request,*args,**kwargs):
        form = SignupForm(request.POST)
        if form.is_valid():
            user = User.objects.create_user(**form.cleaned_data)
            if user is not None:
                login(request,user)
                return redirect('colleges.url')
        return render(
            request,
            template_name='loginSignup.html',
            context={'form':form,'title':'Signup','link_name':'login','message':'invalid credentials'}
        )


