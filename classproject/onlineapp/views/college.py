from django.shortcuts import render, redirect
from django.urls import resolve
from django.contrib import messages

from onlineapp.models import *
from django.views import View
from django.contrib.auth.mixins import LoginRequiredMixin
from onlineapp.forms.colleges import *
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.models import User


class CollegeView(LoginRequiredMixin,View):
    login_url='/login/'
    def get(self,request,*args,**kwargs):
        if kwargs:
            college=College.objects.get(**kwargs)
            students=Student.objects.filter(college=college)
            if kwargs.get('id')!= -1:
                college_id = college.id
            else:
                college_id = college.id
            return render(
                request,
                template_name='students.html',
                context={'students':students,'college':college,'college_id':college_id})
        colleges=College.objects.all()
        return render(
            request,
            template_name='colleges.html',
            context={
                'colleges' : colleges
            }
        )

class AddCollegeView(LoginRequiredMixin,View):
    login_url='/login/'
    def get(self,request,*args,**kwargs):
        if resolve(request.path_info).url_name == 'edit_college.url':
            college=College.objects.get(**kwargs)
            form=AddCollege(instance=college)
            return render(
                request,
                template_name='forms.html',
                context={
                    'form': form,
                }
            )
        elif resolve(request.path_info).url_name == 'delete_college.url':
            College.objects.get(**kwargs).delete()
            return redirect("colleges.url")
        form = AddCollege()
        return render(
            request,
            template_name="forms.html",
            context={'form':form,'title':'Add College'})
    def post(self,request,**kwargs):
        if kwargs:
            college=College.objects.get(**kwargs)
            form=AddCollege(request.POST,instance=college)
        else:
            form=AddCollege(request.POST)
        if form.is_valid():
            form.save()
            return redirect('colleges.url')
        return render(request,template_name='onlineapp/add_colleges.html',context={'form':form})

class AddStudentView(LoginRequiredMixin,View):
    login_url='/login/'
    def get(self,request,*args,**kwargs):
        if resolve(request.path_info).url_name=='edit_student.url':
            student=Student.objects.get(id=kwargs['student_id'])
            mocktest1=MockTest1.objects.get(student=kwargs['student_id'])
            student_form = AddStudent(instance=student)
            mocktest1_form=AddMockTest1(instance=mocktest1)
            return render(
                request,
                template_name="student_form.html",
                context={'student_form':student_form,'mocktest1_form':mocktest1_form,'title':'Add Student'})
        if resolve(request.path_info).url_name=='delete_student.url':
            Student.objects.get(id=kwargs['student_id']).delete()
            return redirect('colleges.url')
        student_form = AddStudent()
        mocktest1_form=AddMockTest1()
        return render(
            request,
            template_name="student_form.html",
            context={'student_form':student_form,'mocktest1_form':mocktest1_form,'title':'Add Student'})

    def post(self, request, **kwargs):
        if resolve(request.path_info).url_name=='edit_student.url':
            student=Student.objects.get(id=kwargs['student_id'])
            student_form=AddStudent(request.POST,instance=student)
            mocktest1_form=AddMockTest1(request.POST,instance=MockTest1.objects.get(student=kwargs['student_id']))
        else:
            student_form=AddStudent(request.POST)
            mocktest1_form=AddMockTest1(request.POST)
        if student_form.is_valid():
            s=student_form.save(commit=False)
            if resolve(request.path_info).url_name != 'edit_student.url':
                s.college=College.objects.get(id=kwargs['college_id'])
            s.save()
            m=mocktest1_form.save(commit=False)
            m.total=m.problem1+m.problem2+m.problem3+m.problem4
            m.student=s
            m.save()
            return redirect('colleges.url')


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

def logout_user(request):
    logout(request)
    return redirect('login')