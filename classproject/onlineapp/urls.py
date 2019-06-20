from django.conf import settings
from django.conf.urls import include,url
from django.contrib import admin
from django.urls import path, include
import debug_toolbar
from rest_framework.authtoken import views

from onlineapp.views.college import *
from onlineapp.restFramework import *
from onlineapp.views.testUrls import myFirstTestView

urlpatterns = [
    path('',lambda x: redirect('login',permanent=True)),
    path('get_colleges/',CollegeView.as_view(),name='colleges.url'),
    path('get_colleges/<int:id>/',CollegeView.as_view(),name='college_details.url'),
    path('get_colleges/<str:acronym>/',CollegeView.as_view(),name='college_details.url'),
    path('add_colleges/', AddCollegeView.as_view(),name='add_colleges.url'),
    path('get_colleges/edit_college/<int:id>/', AddCollegeView.as_view(), name='edit_college.url'),
    path('get_colleges/delete_college/<int:id>/', AddCollegeView.as_view(), name='delete_college.url'),
    path('get_colleges/<int:college_id>/add_students/',AddStudentView.as_view(),name='add_student.url'),
    path('get_colleges/<int:college_id>/edit_student/<int:student_id>/',AddStudentView.as_view(),name='edit_student.url'),
    path('get_colleges/<int:college_id>/delete_student/<int:student_id>/',AddStudentView.as_view(),name='delete_student.url'),
    path('login/', LoginController.as_view(),name = 'login'),
    path('signup/', SignupController.as_view(),name = 'signup'),
    path('logout/', logout_user, name='logout'),
    path('api/v1/colleges/', college_list, name='api_colleges'),
    path('api/v1/colleges/<int:id>/college_details/', college_details,name='api_college_details'),
    path('api/v1/colleges/<int:id>/student_details/', student_list,name='api_student_details'),
    path('test_path/', myFirstTestView,name='first_test.url'),
    url(r'^api-token-auth/', views.obtain_auth_token),
]