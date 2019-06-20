from tokenize import Token

from py._xmlgen import unicode
from rest_framework import status
from rest_framework.authtoken.views import ObtainAuthToken
from rest_framework.decorators import api_view, authentication_classes, permission_classes
from rest_framework.authentication import SessionAuthentication, BasicAuthentication, TokenAuthentication
from rest_framework.permissions import IsAuthenticated
from rest_framework.response import Response
from onlineapp.serializers import *


@api_view(['GET', 'POST'])
@authentication_classes((SessionAuthentication, BasicAuthentication,TokenAuthentication))
@permission_classes((IsAuthenticated,))
def college_list(request):
    if request.method == 'GET':
        colleges = College.objects.all()
        serializer = CollegeSerializer(colleges, many=True)
        return Response(serializer.data)

    elif request.method == 'POST':
        serializer = CollegeSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

@api_view(['GET', 'PUT','DELETE'])
@authentication_classes((SessionAuthentication, BasicAuthentication,TokenAuthentication))
@permission_classes((IsAuthenticated,))
def college_details(request,id):
    college = College.objects.get(id=id)
    if request.method == 'GET':
        serializer = CollegeSerializer(college)
        return Response(serializer.data)

    elif request.method == 'PUT':
        serializer = CollegeSerializer(data=request.data,instance=college)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    elif request.method == 'DELETE':
        college.delete()
        return Response(status=status.HTTP_201_CREATED)
        return Response(status=status.HTTP_400_BAD_REQUEST)

@api_view(['GET', 'POST','PUT'])
@authentication_classes((SessionAuthentication, BasicAuthentication,TokenAuthentication))
@permission_classes((IsAuthenticated,))
def student_list(request,id):
    college = College.objects.get(id=id)
    if request.method == 'GET':
        students = Student.objects.filter(college=college)
        serializer = StudentSerializer(students, many=True)
        return Response(serializer.data)
    elif request.method == 'POST':
        serializer = StudentSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
    elif request.method == 'PUT':
        serializer = StudentSerializer(data=request.data, instance=college)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)


# class CustomAuthToken(ObtainAuthToken):
#
#     def post(self, request, *args, **kwargs):
#         serializer = self.serializer_class(data=request.data,
#                                            context={'request': request})
#         serializer.is_valid(raise_exception=True)
#         user = serializer.validated_data['user']
#         token, created = Token.objects.get_or_create(user=user)
#         return Response({
#             'token': token.key,
#             'user_id': user.pk
#         })