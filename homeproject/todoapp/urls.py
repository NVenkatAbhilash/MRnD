from django.urls import path

from todoapp.views import *
#from todoapp.views import LoginController, SignupController

urlpatterns = [
    #path('login/', LoginController.as_view(),name = 'login'),
    #path('signup/', SignupController.as_view(),name = 'signup'),
    path('to_do_list/', ListView.as_view(), name='list_url'),
    path('to_do_items/<int:pk>/to_do_list', ItemsView.as_view(), name = 'items_url'),
]